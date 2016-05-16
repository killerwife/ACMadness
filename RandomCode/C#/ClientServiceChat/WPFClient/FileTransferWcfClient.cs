using System.ServiceModel;
using System.ServiceModel.Channels;
using SharedComponents;

namespace WPFClient
{
    class FileTransferWcfClient : ClientBase<IFileTransferService>
    {
        private IFileTransferService _proxy;

        public FileTransferWcfClient( Binding binding, EndpointAddress epAddr)
        : base(binding, epAddr)
        {

        }

        public void SetProxy(IFileTransferService proxy)
        {
            _proxy = proxy;
        }

        public long DownloadFile(ref string fileName, out System.IO.Stream fileByteStream)
        {
            DownloadRequest inValue = new DownloadRequest {FileName = fileName};
            RemoteFileInfo retVal = _proxy.DownloadFile(inValue);
            fileName = retVal.FileName;
            fileByteStream = retVal.FileByteStream;
            return retVal.Length;
        }

        public void UploadFile(string fileName, long length, System.IO.Stream fileByteStream)
        {
            RemoteFileInfo inValue = new RemoteFileInfo
            {
                FileName = fileName,
                Length = length,
                FileByteStream = fileByteStream
            };
            _proxy.UploadFile(inValue);
        }
    }
}
