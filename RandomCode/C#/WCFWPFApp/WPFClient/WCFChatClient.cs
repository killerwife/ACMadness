using System;
using System.ServiceModel;
using System.ServiceModel.Channels;
using System.Threading;
using SharedComponents;
using Message = SharedComponents.Message;

namespace WPFClient
{
    /// <summary>
    /// Wrapper class that handles communication with an IChat interface service.
    /// </summary>
    class WcfChatClient : DuplexClientBase<IChat>
    {
        /// <summary>
        /// Proxy with channel for communication with service.
        /// </summary>
        IChat _proxy;
        public event EventHandler<ConnectCompletedEventArgs> ConnectCompleted;

        public WcfChatClient(InstanceContext inputInstance, Binding binding, EndpointAddress epAddr)
        : base(inputInstance, binding, epAddr)
        {

        }

        /// <summary>
        /// Sets the proxy.
        /// </summary>
        /// <param name="proxy"></param>
        public void SetProxy(IChat proxy)
        {
            _proxy = proxy;
        }

        /// <summary>
        /// Invokes IChat Connect method in a separate thread.
        /// </summary>
        /// <param name="client">Name of the connecting client.</param>
        public void ConnectAsync(SharedComponents.Client client)
        {
            Thread thread = new Thread(() =>
            {
                bool result = _proxy.Connect(client);
                ConnectCompleted?.Invoke(this, new ConnectCompletedEventArgs(new object[] { result }));
            });
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();
        }

        /// <summary>
        /// Invokes IChat Disconnect method in a separate thread and closes the proxy channel.
        /// </summary>
        /// <param name="client">Name of the disconnecting client.</param>
        public void DisconnectAsync(SharedComponents.Client client)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.Disconnect(client);
                Close();
            });
            thread.Start();
        }

        /// <summary>
        /// Invokes the IChat Whisper method in a separate thread.
        /// </summary>
        /// <param name="msg">Message of the whisper.</param>
        /// <param name="receiver">Client which should receive the message.</param>
        public void WhisperAsync(Message msg, SharedComponents.Client receiver)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.Whisper(msg, receiver);
            });
            thread.Start();
        }


        /// <summary>
        /// Invokes the IChat Say method in a separate thread.
        /// </summary>
        /// <param name="msg">Message that will be broadcast to all chat members.</param>
        public void SayAsync(Message msg)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.Say(msg);
            });
            thread.Start();
        }

        /// <summary>
        /// Invokes the IChat IsWriting method in a separate thread.
        /// </summary>
        /// <param name="sender">Client which is writing.</param>
        public void IsWritingAsync(SharedComponents.Client sender)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.IsWriting(sender);
            });
            thread.Start();
        }

        /// <summary>
        /// Invokes the IChat SendFileToClient method in a separate thread.
        /// </summary>
        /// <param name="receiver">Client which should receive the file.</param>
        /// <param name="filename">File which the client should receive.</param>
        public void SendFileToClientAsync(SharedComponents.Client sender,SharedComponents.Client receiver, string filename)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.SendFileToClient(sender,receiver, filename);
            });
            thread.Start();
        }


        /// <summary>
        /// Invokes the IChat DeleteFile method in a separate thread.
        /// </summary>
        /// <param name="filePath">Path of the file for deletion.</param>
        public void DeleteFileAsync(SharedComponents.Client client,string filePath)
        {
            Thread thread = new Thread(() =>
            {
                _proxy.FinaliseFileTransfer(client,filePath);
            });
            thread.Start();
        }
    }

    /// <summary>
    /// Return value class for the connect operation.
    /// </summary>
    public class ConnectCompletedEventArgs : EventArgs
    {
        private readonly object[] _results;

        public ConnectCompletedEventArgs(object[] results)
        {
            _results = results;
        }

        public bool Result => (bool)_results[0];
    }
}
