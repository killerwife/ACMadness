using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.ServiceModel;

namespace SharedComponents
{

    /// <summary>
    /// Implementation of IChat interface.
    /// Defines service operations and acts as a synchronisation monitor for network operation.
    /// </summary>
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.Single,
    ConcurrencyMode = ConcurrencyMode.Multiple, UseSynchronizationContext = false)]
    public class ChatService : IChat,IFileTransferService
    {
        readonly ConcurrentDictionary<Client, IChatCallback> _clients = new ConcurrentDictionary<Client, IChatCallback>();

        readonly List<Client> _clientList = new List<Client>();

        public IChatCallback CurrentCallback => OperationContext.Current.GetCallbackChannel<IChatCallback>();

        //readonly object _syncObj = new object();

        private bool SearchClientsByName(string name)
        {
            return _clients.Keys.Any(c => c.Name == name);
        }

        #region IChat Members

        public bool Connect(Client client)
        {
            if (!_clients.ContainsKey(client) && !SearchClientsByName(client.Name))
            {

                _clients.TryAdd(client, CurrentCallback);
                _clientList.Add(client);

                foreach (Client key in _clients.Keys)
                {
                    IChatCallback callback = _clients[key];
                    try
                    {
                        callback.RefreshClients(_clientList);
                        callback.UserJoin(client);
                    }
                    catch
                    {
                        _clients.TryRemove(key, out callback);
                        return false;
                    }

                }
                return true;
            }
            return false;
        }

        public void Say(Message msg)
        {
            foreach (IChatCallback callback in _clients.Values)
            {
                callback.Receive(msg);
            }
        }

        public void Whisper(Message msg, Client receiver)
        {

            foreach (Client rec in _clients.Keys)
            {
                if (rec.Name == receiver.Name)
                {
                    IChatCallback callback = _clients[rec];
                    callback.ReceiveWhisper(msg, rec);

                    foreach (Client sender in _clients.Keys)
                    {
                        if (sender.Name == msg.Sender)
                        {
                            IChatCallback senderCallback = _clients[sender];
                            senderCallback.ReceiveWhisper(msg, rec);
                            return;
                        }
                    }
                }
            }

        }


       /* public bool SendFile(FileMessage fileMsg, Client receiver)
        {
            foreach (Client rcvr in _clients.Keys)
            {
                if (rcvr.Name == receiver.Name)
                {
                    Message msg = new Message
                    {
                        Sender = fileMsg.Sender,
                        Content = "I'M SENDING FILE.. " + fileMsg.FileName
                    };

                    IChatCallback rcvrCallback = _clients[rcvr];
                    rcvrCallback.ReceiveWhisper(msg, receiver);
                    rcvrCallback.ReceiverFile(fileMsg, receiver);

                    foreach (Client sender in _clients.Keys)
                    {
                        if (sender.Name == fileMsg.Sender)
                        {
                            IChatCallback sndrCallback = _clients[sender];
                            sndrCallback.ReceiveWhisper(msg, receiver);
                            return true;
                        }
                    }
                }
            }
            return false;
        }*/

        public void IsWriting(Client client)
        {
            foreach (IChatCallback callback in _clients.Values)
            {
                callback.IsWritingCallback(client);
            }
        }

        public void Disconnect(Client client)
        {
            foreach (Client c in _clients.Keys.Where(c => client.Name == c.Name))
            {
                IChatCallback temp;
                _clients.TryRemove(c, out temp);
                _clientList.Remove(c);
                foreach (IChatCallback callback in _clients.Values)
                {
                    callback.RefreshClients(_clientList);
                    callback.UserLeave(client);
                }
                return;
            }
        }

        /// <summary>
        /// Tells client to establish connection for file streaming.
        /// </summary>
        /// <param name="sender">Client that sent the file.</param>
        /// <param name="receiver">Client that will receive the file.</param>
        /// <param name="filename">File that the client will receive.</param>
        public void SendFileToClient(Client sender,Client receiver,string filename)
        {
            foreach (Client c in _clients.Keys.Where(c => receiver.Name == c.Name))
            {
                IChatCallback temp;
                _clients.TryGetValue(c,out temp);
                temp?.PrepareForFile(sender, filename);
            }
        }

        /// <summary>
        /// Deletes file from service and sends confirmation to client.
        /// </summary>
        /// <param name="client"></param>
        /// <param name="filename"></param>
        public void FinaliseFileTransfer(Client client,string filename)
        {
            File.Delete(filename);
            foreach (Client c in _clients.Keys.Where(c => client.Name == c.Name))
            {
                IChatCallback temp;
                _clients.TryGetValue(c, out temp);
                temp?.FileSendingDone();
            }
        }

        #endregion

        /// <summary>
        /// Sends a stream for given requested file.
        /// </summary>
        /// <param name="request">File that will be downloaded from the service.</param>
        /// <returns></returns>
        public RemoteFileInfo DownloadFile(DownloadRequest request)
        {
            // get some info about the input file
            string filePath = Path.Combine("Upload", request.FileName);
            FileInfo fileInfo = new FileInfo(filePath);

            // report start
            Console.WriteLine("Sending stream " + request.FileName + " to client");
            Console.WriteLine("Size " + fileInfo.Length);

            // check if exists
            if (!fileInfo.Exists) throw new FileNotFoundException("File not found", request.FileName);

            // open stream
            FileStream stream = new FileStream(filePath, FileMode.Open, FileAccess.Read);

            // return result
            RemoteFileInfo result = new RemoteFileInfo
            {
                FileName = request.FileName,
                Length = fileInfo.Length,
                FileByteStream = stream
            };
            // return file stream
            return result;

            // after returning to the client download starts. Stream remains open and on server and the client reads it, although the execution of this method is completed.
        }

        /// <summary>
        /// Uploads a file that is passed as a stream.
        /// </summary>
        /// <param name="request">Stream of file for upload.</param>
        public void UploadFile(RemoteFileInfo request)
        {
            // report start
            Console.WriteLine("Start uploading " + request.FileName);
            Console.WriteLine("Size " + request.Length);

            // create output folder, if does not exist
            if (!Directory.Exists("Upload"))Directory.CreateDirectory("Upload");

            // kill target file, if already exists
            string filePath = Path.Combine("Upload", request.FileName);
            if (File.Exists(filePath)) File.Delete(filePath);

            int chunkSize = 2048;
            byte[] buffer = new byte[chunkSize];

            using (FileStream writeStream = new FileStream(filePath, FileMode.CreateNew, FileAccess.Write))
            {
                do
                {
                    // read bytes from input stream
                    int bytesRead = request.FileByteStream.Read(buffer, 0, chunkSize);
                    if (bytesRead == 0) break;

                    // write bytes to output stream
                    writeStream.Write(buffer, 0, bytesRead);
                } while (true);

                // report end
                Console.WriteLine("Done!");
                // close stream at the end of reading
                writeStream.Close();
            }
        }
    }
}
