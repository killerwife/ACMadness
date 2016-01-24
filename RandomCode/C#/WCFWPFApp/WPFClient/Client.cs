using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.IO;
using System.Reflection;
using System.ServiceModel;
using System.Collections.ObjectModel;
using System.Linq;
using System.Threading;
using System.Windows.Threading;
using SharedComponents;
using ViewModel;
using Application = System.Windows.Application;
using FlowDirection = System.Windows.FlowDirection;
using KeyEventArgs = System.Windows.Input.KeyEventArgs;
using MessageBox = System.Windows.MessageBox;
using Orientation = System.Windows.Controls.Orientation;

namespace WPFClient
{

    /// <summary>
    /// Chat client that implements all necessary methods for communication.
    /// GUI operations are done via view model.
    /// </summary>
    class Client : IChatCallback
    {
        //SVC holds references to the proxy and cotracts..
        WcfChatClient _channel;
        FileTransferWcfClient _fileChannel;
        SharedComponents.Client _receiver;
        /// <summary>
        /// Client of this chat instance.
        /// </summary>
        SharedComponents.Client _localClient;
        //arrays for encrypted messages
        private readonly List<string> _messages;
        private readonly List<string> _msgIds;
        //list of users who sent the corresponding message
        private readonly ClientViewModel _viewModel;

        //When the communication object turns to fault state it will
        //require another thread to invoke a fault event
        private delegate void FaultedInvoker();

        //This will hold each online client with a listBoxItem to quickly handle adding
        //and removing clients when they join or leave
        private readonly Dictionary<ListBoxItem, SharedComponents.Client> _onlineClients;

        /// <summary>
        ///initialise lists and view model
        /// </summary>
        public Client(ClientViewModel viewModel)
        {
            _viewModel = viewModel;
            _msgIds = new List<string>();
            _onlineClients = new Dictionary<ListBoxItem, SharedComponents.Client>();
            _messages = new List<string>();
            if (!Directory.Exists("Download")) Directory.CreateDirectory("Download");
        }


        //Service might be disconnected or stopped for any reason,
        //so we have to handle the state of the communication object,
        //the communication object will fire an event for each transitioning
        //from a state to another, notice that when a connection state goes
        //from opening to opened or from opened to closing state.. it can't go
        //back so, if it is closed or faulted you have to set the proxy = null;
        //to be able to create a proxy again and open a connection
        //..
        //I have made a method called HandleProxy() to handle the state
        //of the connection, so in each event like opened, closed or faulted
        //we will call this method, and it will switch on the connection state
        //and apply a suitable reaction.
        //..
        //Because this events will need to be invoked on another thread
        //you can do like so in WPF applications

        void InnerDuplexChannel_Closed(object sender, EventArgs e)
        {
            var dispatcher = Application.Current.Dispatcher;
            if (!dispatcher.CheckAccess())
            {
                dispatcher.BeginInvoke(DispatcherPriority.Normal, new FaultedInvoker(HandleProxy));
                return;
            }
            HandleProxy();
        }

        void InnerDuplexChannel_Opened(object sender, EventArgs e)
        {
            var dispatcher = Application.Current.Dispatcher;
            if (!dispatcher.CheckAccess())
            {
                dispatcher.BeginInvoke(DispatcherPriority.Normal, new FaultedInvoker(HandleProxy));
                return;
            }
            HandleProxy();
        }

        void InnerDuplexChannel_Faulted(object sender, EventArgs e)
        {
            var dispatcher = Application.Current.Dispatcher;
            if (!dispatcher.CheckAccess())
            {
                dispatcher.BeginInvoke(DispatcherPriority.Normal, new FaultedInvoker(HandleProxy));
                return;
            }
            HandleProxy();
        }

        #region Private Methods

        /// <summary>
        /// This is the most method I like, it helps us alot
        /// We may can't know when a connection is lost in 
        /// of network failure or service stopped.
        /// And also to maintain performance client doesnt know
        /// that the connection will be lost when hitting the 
        /// disconnect button, but when a session is terminated
        /// this method will be called, and it will handle everything.
        /// </summary>
        private void HandleProxy()
        {
            if (_channel != null)
            {
                switch (_channel.State)
                {
                    case CommunicationState.Closed:
                        _channel = null;
                        _viewModel.CloseConnection();
                        break;
                    case CommunicationState.Closing:
                        break;
                    case CommunicationState.Created:
                        break;
                    case CommunicationState.Faulted:
                        _channel.Abort();
                        _channel = null;
                        _viewModel.CloseConnection();
                        break;
                    case CommunicationState.Opened:
                        Dictionary<int, Image> images = GetImages();
                        _viewModel.OpenConnection(_localClient.Name, images);
                        break;
                    case CommunicationState.Opening:
                        break;
                }
            }

        }



        /// <summary>
        /// This is the second important method, which creates 
        /// the proxy, subscribe to connection state events
        /// and open a connection with the service
        /// </summary>
        public void Connect()
        {
            if (_channel == null)
            {
                try
                {
                    _localClient = new SharedComponents.Client
                    {
                        Name = _viewModel.Name,
                        AvatarID = _viewModel.SelectedIndex
                    };
                    InstanceContext context = new InstanceContext(this);

                    //As the address in the configuration file is set to localhost
                    //we want to change it so we can call a service in internal 
                    //network, or over internet
                    string servicePath = "/WPFHost/tcp";
                    string[] address = _viewModel.ConnectionIP.Split(':');
                    var binding = new NetTcpBinding("NetTcpBinding");
                    var endAdd = new EndpointAddress("net.tcp://" + address[0] + ":" + address[1] + servicePath);
                    _channel = new WcfChatClient(context, binding, endAdd);
                    _channel.Open();
                    _channel.InnerDuplexChannel.Faulted += InnerDuplexChannel_Faulted;
                    _channel.InnerDuplexChannel.Opened += InnerDuplexChannel_Opened;
                    _channel.InnerDuplexChannel.Closed += InnerDuplexChannel_Closed;
                    _channel.SetProxy(_channel.ChannelFactory.CreateChannel());
                    _channel.ConnectCompleted += proxy_ConnectCompleted;
                    //_channel.Connect(_localClient);
                    //_channel.ConnectCompleted += (proxy_ConnectCompleted);
                    _messages.Clear();
                    _msgIds.Clear();
                    //load all previous messages from database
                    _channel.ConnectAsync(_localClient);
                    //proxy_ConnectCompleted(output);
                    using (var temp = new ChatDataContainer())
                    {
                        var user = temp.ChatUsersSet.Where(s => s.Username == _viewModel.Name).ToList();
                        if (user.Count == 0)
                        {
                            var newuser = new ChatUsers
                            {
                                AvatarID = _viewModel.SelectedIndex,
                                Username = _viewModel.Name
                            };
                            temp.ChatUsersSet.Add(newuser);
                            temp.SaveChanges();
                        }
                        var cur = temp.ChatUsersSet.SingleOrDefault(t => t.Username == _viewModel.Name);
                        if (cur != null)
                        {
                            long id = cur.Id;
                            var userlist = temp.ChatUsersSet.Select(s => new { ID = s.Id, Avatar = s.AvatarID, Name = s.Username });
                            foreach (var row in temp.ChatDataSet.Where(s => s.Id == id))
                            {
                                var currentUser = userlist.Where(s => s.ID == row.Id).ToList();
                                ListBoxItem item = MakeItem(currentUser[0].Avatar, currentUser[0].Name + " : " + row.Message);
                                _viewModel.ChatMsgs.Add(item);
                                _messages.Add(row.Message);
                                _msgIds.Add(currentUser[0].Name);
                                _viewModel.ScrollDown();
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    _viewModel.Name = ex.Message;
                    _viewModel.ChatStatusLabel = "Offline";
                    _viewModel.ConnectButtonIsEnabled = true;
                }
            }
            else
            {
                HandleProxy();
            }
        }

        /// <summary>
        /// This method encrypts the message we want to send
        /// and sends it either to one recipient (whisper)
        /// or all online chat clients
        /// </summary>
        public void Send()
        {
            if (_channel != null && _viewModel.ChatInputText != "")
            {
                if (_channel.State == CommunicationState.Faulted)
                {
                    HandleProxy();
                }
                else
                {
                    //Create message, assign its properties
                    //encrypt message
                    string temp = "";
                    switch (_viewModel.SelectedCypher)
                    {
                        case (int)Cyphers.SimpleEncryption:
                            var cypher1 = new SimpleEncryption();
                            temp = cypher1.EncryptMessage(_viewModel.ChatInputText, _viewModel.Key);
                            break;
                        case (int)Cyphers.Rijndael:
                            var cypher2 = new Rijndael();
                            temp = cypher2.EncryptMessage(_viewModel.ChatInputText, _viewModel.Key);
                            break;
                    }
                    Message msg = new Message
                    {
                        Sender = _localClient.Name,
                        Time = DateTime.Now,
                        Content = temp
                    };
                    //If whisper mode is checked and an item is
                    //selected in the list box of clients, it will
                    //arrange a client object called receiver
                    //to whisper
                    if (_viewModel.WhisperBox)
                    {
                        if (_receiver != null)
                        {
                            _channel.WhisperAsync(msg, _receiver);
                            _viewModel.ChatInputText = "";
                        }
                    }
                    else
                    {
                        _channel.SayAsync(msg);
                        _viewModel.ChatInputText = "";
                    }
                    //Tell the service to tell back all clients that this client
                    //has just finished typing..
                    _channel.IsWritingAsync(null);
                }
            }
        }

        /// <summary>
        /// This is an important method which is called whenever
        /// a message comes from the service, a client joins or
        /// leaves, to return a ready item to be added in the
        /// list box (either the one for messages or the one for
        /// clients).
        /// </summary>
        /// <param name="imgID"></param>
        /// <param name="text"></param>
        /// <returns></returns>
        public ListBoxItem MakeItem(int imgID, string text)
        {
            ListBoxItem item = new ListBoxItem();
            Dictionary<int, Image> images = GetImages();
            Image img = images[imgID];
            img.Height = 70;
            img.Width = 60;
            item.Content = img;

            TextBlock txtblock = new TextBlock
            {
                Text = text,
                VerticalAlignment = VerticalAlignment.Center
            };

            StackPanel panel = new StackPanel { Orientation = Orientation.Horizontal };
            panel.Children.Add(item);
            panel.Children.Add(txtblock);

            ListBoxItem bigItem = new ListBoxItem { Content = panel };

            return bigItem;
        }




        /// <summary>
        /// This method is not used, I just put it here to help
        /// you in case you want to make a rich text box and enable
        /// emoticons for example.
        /// Just add a richTextBox control and set
        /// richTextBox.Document = MakeDocument(imgid, text);
        /// </summary>
        /// <param name="imgID"></param>
        /// <param name="text"></param>
        /// <returns></returns>
        // ReSharper disable once UnusedMember.Local on purpose
        private FlowDocument MakeDocument(int imgID, string text)
        {
            Dictionary<int, Image> images = GetImages();
            Image img = images[imgID];
            img.Height = 70;
            img.Width = 60;


            Block imgBlock = new BlockUIContainer(img);
            Block txtBlock = new Paragraph(new Run(text));


            FlowDocument doc = new FlowDocument();
            doc.Blocks.Add(imgBlock);

            doc.Blocks.Add(txtBlock);

            doc.FlowDirection = FlowDirection.LeftToRight;
            return doc;
        }

        /// <summary>
        /// A method to retreive avatars as stream objects
        /// and get an objects of type Image from the stream,
        /// to return a dictionary of images and an ID for each
        /// image.
        /// </summary>
        /// <returns></returns>
        public Dictionary<int, Image> GetImages()
        {
            Assembly asmb = Assembly.GetExecutingAssembly();
            string[] picNames = asmb.GetManifestResourceNames();

            List<Stream> picsStrm = picNames.Where(s => s.EndsWith(".png")).Select(s => asmb.GetManifestResourceStream(s)).Where(strm => strm != null).ToList();

            Dictionary<int, Image> images = new Dictionary<int, Image>();

            int i = 0;

            foreach (Stream strm in picsStrm)
            {

                PngBitmapDecoder decoder = new PngBitmapDecoder(strm,
                    BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
                BitmapSource bitmap = decoder.Frames[0];
                Image img = new Image
                {
                    Source = bitmap,
                    Stretch = Stretch.UniformToFill
                };

                images.Add(i, img);
                i++;

                strm.Close();
            }
            return images;
        }

        #endregion


        #region UI_Events
        /// <summary>
        /// Disconnects the chat client from the proxy
        /// </summary>
        public void Disconnect()
        {
            if (_channel != null)
            {
                if (_channel.State == CommunicationState.Opened)
                {
                    try
                    {
                        _channel.DisconnectAsync(_localClient);
                        //dont set proxy.Close(); because isTerminating = true on Disconnect()
                        //and this by default will call HandleProxy() to take care of this.
                    }
                    catch (TimeoutException ex)
                    {
                        MessageBox.Show(ex.ToString(), "Timeout exception", MessageBoxButton.OK);
                    }
                }
                else
                {
                    HandleProxy();
                }
            }
        }

        /// <summary>
        /// Cascade for pressing connect button
        /// </summary>
        public void buttonConnect_Click()
        {
            _channel = null;
            Connect();
        }

        /// <summary>
        /// Executes after proxy connection
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void proxy_ConnectCompleted(object sender, ConnectCompletedEventArgs e)
        {
            if (e.Result)
            {
                HandleProxy();
            }
            else
            {
                _viewModel.LoginStatusLabel = "Name found";
                _viewModel.ConnectButtonIsEnabled = true;
            }
        }

        /// <summary>
        /// Sends is writing message to recipients
        /// </summary>
        public void chatTxtBoxType_KeyUp()
        {
            if (_channel != null)
            {
                if (_channel.State == CommunicationState.Faulted)
                {
                    HandleProxy();
                }
                else
                {
                    if (_viewModel.ChatInputText.Length < 1)
                    {
                        _channel.IsWritingAsync(null);
                    }
                }
            }
        }

        /// <summary>
        /// Sends message if enter is pressed,
        /// else sends is writing message.
        /// </summary>
        /// <param name="e"></param>
        public void chatTxtBoxType_KeyDown(KeyEventArgs e)
        {
            if (_channel != null)
            {
                if (_channel.State == CommunicationState.Faulted)
                {
                    HandleProxy();
                }
                else
                {
                    if (e.Key == Key.Enter)
                    {
                        Send();
                    }
                    else if (_viewModel.ChatInputText.Length < 1)
                    {
                        _channel.IsWritingAsync(_localClient);
                    }
                }
            }
        }

        /// <summary>
        /// Saves the selected online client, for usage when whispering
        /// </summary>
        public void chatListBoxNames_SelectionChanged()
        {
            //If user select an online client, make a client object
            //to be the receiver if the user wants to whisper him.
            ListBoxItem item = _viewModel.ChatNameSelected;
            if (item != null)
            {
                _receiver = _onlineClients[item];
            }
        }


        #endregion
        //methods from mandatory interface
        #region IChatCallback Members

        /// <summary>
        /// Refreshes online clients connected to the proxy
        /// </summary>
        /// <param name="clients"></param>
        public void RefreshClients(List<SharedComponents.Client> clients)
        {
            _viewModel.ChatNames.Clear();
            _onlineClients.Clear();
            foreach (SharedComponents.Client c in clients)
            {
                ListBoxItem item = MakeItem(c.AvatarID, c.Name);
                _viewModel.ChatNames.Add(item);
                _onlineClients.Add(item, c);
            }
        }

        /// <summary>
        /// Handles message receiving and decryption of incoming messages.
        /// </summary>
        /// <param name="msg"></param>
        public void Receive(Message msg)
        {
            foreach (SharedComponents.Client c in _onlineClients.Values)
            {
                if (c.Name == msg.Sender)
                {
                    string output = "";
                    switch (_viewModel.SelectedCypher)
                    {
                        case (int)Cyphers.SimpleEncryption:
                            var cypher1 = new SimpleEncryption();
                            output = msg.Sender + " : " + cypher1.DecryptMessage(msg.Content, _viewModel.Key);
                            break;
                        case (int)Cyphers.Rijndael:
                            var cypher2 = new Rijndael();
                            output = msg.Sender + " : " + cypher2.DecryptMessage(msg.Content, _viewModel.Key);
                            break;
                    }
                    ListBoxItem item = MakeItem(c.AvatarID, output);
                    _viewModel.ChatMsgs.Add(item);
                    _messages.Add(msg.Content);
                    using (var terr = new ChatDataContainer())
                    {
                        var sender = terr.ChatUsersSet.Where(s => s.Username == msg.Sender).ToList();
                        var curUser = terr.ChatUsersSet.Where(s => s.Username == _viewModel.Name).ToList();
                        ChatData temp = new ChatData
                        {
                            Id = curUser[0].Id,
                            Sender = sender[0].Id,
                            Message = msg.Content,
                            RecTime = msg.Time,
                            ChatUsers = curUser[0]
                        };
                        _msgIds.Add(msg.Sender);
                        try
                        {
                            terr.ChatDataSet.Add(temp);
                            terr.SaveChanges();
                        }
                        catch (Exception e)
                        {
                            _viewModel.Name = e.ToString();
                        }

                    }
                }
            }
            _viewModel.ScrollDown();
        }

        /// <summary>
        /// Receives a whisper and decrypts it
        /// </summary>
        /// <param name="msg"></param>
        /// <param name="receiver"></param>
        public void ReceiveWhisper(Message msg, SharedComponents.Client receiver)
        {
            foreach (SharedComponents.Client c in _onlineClients.Values)
            {
                if (c.Name == msg.Sender)
                {
                    string output = "";
                    switch (_viewModel.SelectedCypher)
                    {
                        case (int)Cyphers.SimpleEncryption:
                            var cypher1 = new SimpleEncryption();
                            output = cypher1.DecryptMessage(msg.Content, _viewModel.Key);
                            break;
                        case (int)Cyphers.Rijndael:
                            var cypher2 = new Rijndael();
                            output = cypher2.DecryptMessage(msg.Content, _viewModel.Key);
                            break;
                    }
                    ListBoxItem item = MakeItem(c.AvatarID,
                        msg.Sender + " whispers " + receiver.Name + " : " + output);
                    _viewModel.ChatMsgs.Add(item);
                    _messages.Add(msg.Content);
                    _msgIds.Add(msg.Sender + " whispers " + receiver.Name);
                }
            }
            _viewModel.ScrollDown();
        }

        /// <summary>
        /// Shows is writing a message message
        /// </summary>
        /// <param name="client"></param>
        public void IsWritingCallback(SharedComponents.Client client)
        {
            if (client == null)
            {
                _viewModel.LabelWritingMsg = "";
            }
            else
            {
                _viewModel.LabelWritingMsg += client.Name + " is writing a message.., ";
            }
        }

        /*public void ReceiverFile(FileMessage fileMsg, SharedComponents.Client receiver)
        {
            throw new NotImplementedException();
        }*/

        /// <summary>
        /// Shows user joined message when a user joins
        /// </summary>
        /// <param name="client"></param>
        public void UserJoin(SharedComponents.Client client)
        {
            ListBoxItem item = MakeItem(client.AvatarID,
                "------------ " + client.Name + " joined chat ------------");
            _viewModel.ChatMsgs.Add(item);
            _messages.Add("------------ " + client.Name + " joined chat ------------");
            _msgIds.Add("bla");
            _viewModel.ScrollDown();
        }


        /// <summary>
        /// Shows user left message when a user leaves
        /// </summary>
        /// <param name="client"></param>
        public void UserLeave(SharedComponents.Client client)
        {
            ListBoxItem item = MakeItem(client.AvatarID,
                "------------ " + client.Name + " left chat ------------");
            _viewModel.ChatMsgs.Add(item);
            _messages.Add("------------ " + client.Name + " left chat ------------");
            _msgIds.Add("bla");
            _viewModel.ScrollDown();
        }

        /// <summary>
        /// Opens progress windows, opens http channel, sends request for file download, saves file and tidies up.
        /// </summary>
        /// <param name="client">Client that sent the file.</param>
        /// <param name="filename">File that will be downloaded from service.</param>
        public void PrepareForFile(SharedComponents.Client client, string filename)
        {
            _viewModel.OpenProgressWindow();
            _viewModel.FileWindowModel.FileNameLabel = filename;
            Thread thread = new Thread(() =>
            {
                string[] address = _viewModel.ConnectionIP.Split(':');
                string fileServicePath = "/WPFHost/http";
                var fileEndAdd = new EndpointAddress("http://" + address[0] + ":" + (int.Parse(address[1]) + 1111) + fileServicePath);
                var fileBinding = new BasicHttpBinding("httpBinding");
                _fileChannel = new FileTransferWcfClient(fileBinding, fileEndAdd);
                try
                {
                    // start service client
                    _fileChannel.Open();
                    _fileChannel.SetProxy(_fileChannel.ChannelFactory.CreateChannel());
                    // kill target file, if already exists
                    // get stream from server

                    Stream inputStream;
                    long length = _fileChannel.DownloadFile(ref filename, out inputStream);
                    string filePath = Path.Combine("Download", filename);
                    // write server stream to disk
                    using (FileStream writeStream = new FileStream(filePath, FileMode.CreateNew, FileAccess.Write))
                    {
                        int chunkSize = 2048;
                        byte[] buffer = new byte[chunkSize];
                        _viewModel.FileWindowModel.ProgressMax = length;
                        do
                        {
                            // read bytes from input stream
                            int bytesRead = inputStream.Read(buffer, 0, chunkSize);
                            if (bytesRead == 0) break;

                            // write bytes to output stream
                            writeStream.Write(buffer, 0, bytesRead);

                            // report progress from time to time
                            _viewModel.FileWindowModel.Progress = writeStream.Position;
                        } while (true);

                        writeStream.Close();
                        Thread threadClose = new Thread(() =>
                        {
                            _viewModel.FileWindowModel.DoneLabel = "Done";
                           // _viewModel.CloseProgressWindow();
                        });
                        threadClose.SetApartmentState(ApartmentState.STA);
                        threadClose.Start();
                    }

                    // close service client
                    //inputStream.Close();
                    _fileChannel.Close();
                    _channel.DeleteFileAsync(client, Path.Combine("Upload", filename));
                }
                catch (Exception ex)
                {
                    _viewModel.Name = ex.ToString();
                }
            });
            thread.Start();
        }

        /// <summary>
        /// Uploads a file to the service and sends signal for service to send the file to a different client.
        /// </summary>
        public void UploadFile()
        {
            if (_receiver.Name!=null&&_viewModel.Name == _receiver.Name)
            {
                MessageBoxResult result = MessageBox.Show("Select a file receiver.");
                return;
            }
            _viewModel.FileWindowModel.DoneLabel = "Uploading to service";
            Thread thread = new Thread(() =>
            {
                string[] address = _viewModel.ConnectionIP.Split(':');
                string fileServicePath = "/WPFHost/http";
                var fileEndAdd = new EndpointAddress("http://" + address[0] + ":" + (int.Parse(address[1]) + 1111) + fileServicePath);
                var fileBinding = new BasicHttpBinding("httpBinding");
                _fileChannel = new FileTransferWcfClient(fileBinding, fileEndAdd);
                try
                {
                    _fileChannel.Open();
                    _fileChannel.SetProxy(_fileChannel.ChannelFactory.CreateChannel());
                    // get some info about the input file
                    FileInfo fileInfo = new FileInfo(_viewModel.FileWindowModel.SelectedFile);
                    _viewModel.FileWindowModel.ProgressMax = fileInfo.Length;
                    // open input stream
                    using (FileStream stream = new FileStream(_viewModel.FileWindowModel.SelectedFile, FileMode.Open, FileAccess.Read))
                    {
                        using (StreamWithProgress uploadStreamWithProgress = new StreamWithProgress(stream))
                        {
                            uploadStreamWithProgress.ProgressChanged += uploadStreamWithProgress_ProgressChanged;

                            // upload file
                            _fileChannel.UploadFile(fileInfo.Name, fileInfo.Length, uploadStreamWithProgress);
                        }
                    }
                    // close service client
                    _fileChannel.Close();
                    _channel.SendFileToClientAsync(_localClient,_receiver, fileInfo.Name);
                    _viewModel.FileWindowModel.DoneLabel = "Sending to client";
                }
                catch (Exception ex)
                {
                    _viewModel.Name = ex.ToString();
                }
            });
            thread.Start();
        }

        public void FileSendingDone()
        {
            _viewModel.FileWindowModel.DoneLabel = "Done";
        }

        /// <summary>
        /// Action that will be fired when progress is changed in a StreamWithProgress stream.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void uploadStreamWithProgress_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            if (e.Length != 0)
                _viewModel.FileWindowModel.Progress = e.BytesRead;
        }

        #region Async

        public IAsyncResult BeginUserLeave(SharedComponents.Client client, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndUserLeave(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginUserJoin(SharedComponents.Client client, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndUserJoin(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginReceiverFile(FileMessage fileMsg, SharedComponents.Client receiver, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndReceiverFile(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginIsWritingCallback(SharedComponents.Client client, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndIsWritingCallback(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginReceiveWhisper(Message msg, SharedComponents.Client receiver, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndReceiveWhisper(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginReceive(Message msg, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndReceive(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        public IAsyncResult BeginRefreshClients(List<SharedComponents.Client> clients, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndRefreshClients(IAsyncResult result)
        {
            throw new NotImplementedException();
        }

        #endregion

        #endregion

        /// <summary>
        /// Decrypts all messages shown again
        /// </summary>
        public void Decrypt()
        {
            ObservableCollection<ListBoxItem> msgs = _viewModel.ChatMsgs;
            int i = 0;
            foreach (var row in msgs)
            {
                var panel = row.Content as StackPanel;
                if (panel != null)
                    foreach (object child in panel.Children)
                    {
                        if (child is TextBlock)
                        {
                            var temp = child as TextBlock;
                            if (_messages[i].Length > 13 && _messages[i].Substring(0, 13) == "------------ ")
                            {
                                continue;
                            }
                            switch (_viewModel.SelectedCypher)
                            {
                                case (int)Cyphers.SimpleEncryption:
                                    var cypher1 = new SimpleEncryption();
                                    temp.Text = _msgIds[i] + " : " + cypher1.DecryptMessage(_messages[i], _viewModel.Key);
                                    break;
                                case (int)Cyphers.Rijndael:
                                    var cypher2 = new Rijndael();
                                    temp.Text = _msgIds[i] + " : " + cypher2.DecryptMessage(_messages[i], _viewModel.Key);
                                    break;
                            }
                        }
                    }
                i++;
            }
        }
    }
}
