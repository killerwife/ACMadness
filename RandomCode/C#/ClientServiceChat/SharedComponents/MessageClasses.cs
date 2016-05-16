using System;
using System.Runtime.Serialization;
using System.ServiceModel;

namespace SharedComponents
{
    /// <summary>
    /// Data class for online clients
    /// </summary>
    [DataContract]
    public class Client
    {
        [DataMember]
        public string Name { get; set; }

        [DataMember]
        public int AvatarID { get; set; }

        [DataMember]
        public DateTime Time { get; set; }
    }

    /// <summary>
    /// Data class for messages.
    /// </summary>
    [DataContract]
    public class Message
    {
        [DataMember]
        public string Sender { get; set; }

        [DataMember]
        public string Content { get; set; }

        [DataMember]
        public DateTime Time { get; set; }
    }

    /// <summary>
    /// Data class for file messages.
    /// </summary>
    [DataContract]
    public class FileMessage
    {
        [DataMember]
        public string Sender { get; set; }

        [DataMember]
        public string FileName { get; set; }

        [DataMember]
        public byte[] Data { get; set; }

        [DataMember]
        public DateTime Time { get; set; }
    }

    [MessageContract]
    public class DownloadRequest
    {
        [MessageBodyMember]
        public string FileName;
    }

    [MessageContract]
    public class RemoteFileInfo : IDisposable
    {
        [MessageHeader(MustUnderstand = true)]
        public string FileName;

        [MessageHeader(MustUnderstand = true)]
        public long Length;

        [MessageBodyMember(Order = 1)]
        public System.IO.Stream FileByteStream;

        public void Dispose()
        {
            // close stream when the contract instance is disposed. this ensures that stream is closed when file download is complete, since download procedure is handled by the client and the stream must be closed on server.
            if (FileByteStream != null)
            {
                FileByteStream.Close();
                FileByteStream = null;
            }
        }
    }
}
