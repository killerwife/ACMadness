using System;
using System.IO;

namespace SharedComponents
{
    /// <summary>
    /// Return value class for ProgressChanged event.
    /// </summary>
    public class ProgressChangedEventArgs : EventArgs
    {
        /// <summary>
        /// Bytes that have been read so far.
        /// </summary>
        public long BytesRead;
        /// <summary>
        /// Length of the whole stream.
        /// </summary>
        public long Length;

        public ProgressChangedEventArgs(long bytesRead, long length)
        {
            BytesRead = bytesRead;
            Length = length;
        }
    }

    /// <summary>
    /// Stream class that calls event whenever progress is registered.
    /// </summary>
    public class StreamWithProgress : Stream
    {
        /// <summary>
        /// File that is being read.
        /// </summary>
        private readonly FileStream _file;
        /// <summary>
        /// Length of the read file.
        /// </summary>
        private readonly long _length;
        /// <summary>
        /// Event that is fired whenever progress is registered.
        /// </summary>
        public event EventHandler<ProgressChangedEventArgs> ProgressChanged;

        /// <summary>
        /// Bytes that have been read so far.
        /// </summary>
        private long _bytesRead;
        
        public StreamWithProgress(FileStream file)
        {
            _file = file;
            _length = file.Length;
            _bytesRead = 0;
            //ProgressChanged?.Invoke(this, new ProgressChangedEventArgs(_bytesRead, _length));
        }

        /// <summary>
        /// Retrieves the current progress of the stream.
        /// </summary>
        /// <returns></returns>
        public double GetProgress()
        {
            return (double)_bytesRead / _file.Length;
        }

        public override bool CanRead => true;

        public override bool CanSeek
        {
            get { return false; }
        }

        public override bool CanWrite => false;

        public override void Flush() { }

        public override long Length
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        public override long Position
        {
            get { return _bytesRead; }
            set { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// Reads the current stream.
        /// </summary>
        /// <param name="buffer">Byte array buffer into which latest bytes are placed.</param>
        /// <param name="offset">Offset of this read step.</param>
        /// <param name="count">Number of bytes that should be read.</param>
        /// <returns></returns>
        public override int Read(byte[] buffer, int offset, int count)
        {
            int result = _file.Read(buffer, offset, count);
            _bytesRead += result;
            ProgressChanged?.Invoke(this, new ProgressChangedEventArgs(_bytesRead, _length));
            return result;
        }

        public override long Seek(long offset, SeekOrigin origin)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public override void SetLength(long value)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}
