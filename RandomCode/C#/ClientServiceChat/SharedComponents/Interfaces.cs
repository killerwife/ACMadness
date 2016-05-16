using System.Collections.Generic;
using System.ServiceModel;

namespace SharedComponents
{
    /// <summary>
    /// Interface for chat operations.
    /// </summary>
    [ServiceContract(CallbackContract = typeof(IChatCallback), SessionMode = SessionMode.Required)]
    public interface IChat
    {
        /// <summary>
        /// Connects client to service.
        /// </summary>
        /// <param name="client">Client that is connecting.</param>
        /// <returns></returns>
        [OperationContract(IsInitiating = true)]
        bool Connect(Client client);

        /// <summary>
        /// Broadcasts a message to all connected chat members.
        /// </summary>
        /// <param name="msg">Message for broadcast.</param>
        [OperationContract(IsOneWay = true)]
        void Say(Message msg);

        /// <summary>
        /// Whisper from a client to a different client.
        /// </summary>
        /// <param name="msg">Message to be whispered.</param>
        /// <param name="receiver">Receiver of the whisper.</param>
        [OperationContract(IsOneWay = true)]
        void Whisper(Message msg, Client receiver);

        /// <summary>
        /// Broadcasts "is writing" message to all chat members.
        /// </summary>
        /// <param name="client">Client that is currently writing.</param>
        [OperationContract(IsOneWay = true)]
        void IsWriting(Client client);

        /// <summary>
        /// Disconnects a client from the service
        /// </summary>
        /// <param name="client">Client for disconnection.</param>
        [OperationContract(IsOneWay = true, IsTerminating = true)]
        void Disconnect(Client client);

        /// <summary>
        /// Sends an already uploaded file to a specific client.
        /// </summary>
        /// <param name="receiver">Client that should receive the file.</param>
        /// <param name="filename">Name/path to the file.</param>
        /// <param name="sender">Client that sent the file.</param>
        [OperationContract(IsOneWay = true)]
        void SendFileToClient(Client sender,Client receiver, string filename);

        /// <summary>
        /// Deletes a file from the service folder and sends notification about file transfer finalisation.
        /// </summary>
        /// <param name="filename">Name/path to the file.</param>
        [OperationContract(IsOneWay = true)]
        void FinaliseFileTransfer(Client client,string filename);
    }

    /// <summary>
    /// Callback interface for IChat operations.
    /// </summary>
    [ServiceContract]
    public interface IChatCallback
    {
        /// <summary>
        /// Refreshes the client list for a client.
        /// </summary>
        /// <param name="clients"></param>
        [OperationContract(IsOneWay = true)]
        void RefreshClients(List<Client> clients);

        /// <summary>
        /// Receive a message from the service.
        /// </summary>
        /// <param name="msg">Message sent.</param>
        [OperationContract(IsOneWay = true)]
        void Receive(Message msg);

        /// <summary>
        /// Receive a whisper from the service from a specific client.
        /// </summary>
        /// <param name="msg">Message sent</param>
        /// <param name="receiver">Client which sent the message.</param>
        [OperationContract(IsOneWay = true)]
        void ReceiveWhisper(Message msg, Client receiver);

        /// <summary>
        /// Sends an "is writing" notification to the client.
        /// </summary>
        /// <param name="client">Client which is writing.</param>
        [OperationContract(IsOneWay = true)]
        void IsWritingCallback(Client client);

        /*[OperationContract(IsOneWay = true)]
        void ReceiverFile(FileMessage fileMsg, Client receiver);*/

        /// <summary>
        /// Sends a "user joined" message to the client.
        /// </summary>
        /// <param name="client">Client which joined.</param>
        [OperationContract(IsOneWay = true)]
        void UserJoin(Client client);

        /// <summary>
        /// Sends a "User left" message.
        /// </summary>
        /// <param name="client">Client which left.</param>
        [OperationContract(IsOneWay = true)]
        void UserLeave(Client client);

        /// <summary>
        /// Sends a notification to prepare for file receival.
        /// </summary>
        /// <param name="client">Client that sent file.</param>
        /// <param name="filename">File name for receival.</param>
        [OperationContract(IsOneWay = true)]
        void PrepareForFile(Client client,string filename);

        /// <summary>
        /// Sends a notification that file transfer is done.
        /// </summary>
        [OperationContract(IsOneWay = true)]
        void FileSendingDone();
    }

    /// <summary>
    /// Interface for file streaming related operations.
    /// </summary>
    [ServiceContract]
    public interface IFileTransferService
    {
        /// <summary>
        /// Uploads a file to the service.
        /// </summary>
        /// <param name="request"></param>
        [OperationContract(IsOneWay = true)]
        void UploadFile(RemoteFileInfo request);

        /// <summary>
        /// Downloads a file from the service to the client.
        /// </summary>
        /// <param name="request"></param>
        /// <returns></returns>
        [OperationContract(IsOneWay = false)]
        RemoteFileInfo DownloadFile(DownloadRequest request);
    }
}
