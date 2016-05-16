
using System.ComponentModel;
using System.Windows.Input;
using PropertyChanged;
using WPFHost;
using WPFHost.Annotations;

namespace ViewModel
{
    /// <summary>
    /// View model for HostWindow functions.
    /// </summary>
    [ImplementPropertyChanged]
    class HostViewModel : INotifyPropertyChanged 
    {
        //server reference
        private readonly Server _server;
        //property bound data members

        //GUI bound properties and commands
        public ICommand ButtonStartCommand => new SharedComponents.DelegateCommand(Start);

        public string LabelStatus { get; set; }

        public string ConnectionIP { get; set; }

        public string ConnectionPort { get; set; }

        public bool ButtonStartVisibility { get; set; }

        public bool ButtonStopVisibility { get; set; }

        public ICommand ButtonStopCommand => new SharedComponents.DelegateCommand(Stop);

        /// <summary>
        /// Initialises server and some GUI properties
        /// </summary>
        public HostViewModel()
        {
            _server=new Server();
            ButtonStartVisibility = true;
            ButtonStopVisibility = false;
            ConnectionIP = "localhost";
            ConnectionPort = "7777";
        }

        /// <summary>
        /// Starts server and changes UI accordingly
        /// </summary>
        public void Start()
        {
            var returnVal = _server.Start(ConnectionIP, ConnectionPort);
            if (returnVal == "")
            {
                LabelStatus = "Opened";
                ButtonStartVisibility = false;
                ButtonStopVisibility = true;
            }
            else
            {
                ConnectionIP = returnVal;
            }
        }

        /// <summary>
        /// Stops server and changes UI accordingly
        /// </summary>
        public void Stop()
        {
            var returnVal = _server.Stop();
            if (returnVal == "")
            {
                LabelStatus = "Closed";
                ButtonStartVisibility = true;
                ButtonStopVisibility = false;
            }
            else
            {
                ConnectionIP = returnVal;
            }
        }

        //Property changed interface implementation
        public event PropertyChangedEventHandler PropertyChanged;

        [NotifyPropertyChangedInvocator]
        protected void RaisePropertyChangedEvent(string propertyName)
        {
            var handler = PropertyChanged;
            handler?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
