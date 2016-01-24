
using System.Windows;
using System.Windows.Input;
using Microsoft.Win32;
using PropertyChanged;
using WPFClient;

namespace ViewModel
{
    /// <summary>
    /// View model that handles all FileTransferClient functions.
    /// </summary>
    [ImplementPropertyChanged]
    class FtcViewModel
    {
        public Client Client;

        public FtcViewModel()
        {
            Progress = 0;
            ProgressMax = 0;
        }
        public double Progress { get; set; }
        public double ProgressMax { get; set; }

        public string SelectedFile { get; set; }

        public string FileNameLabel { get; set; }

        public string DoneLabel { get; set; }

        public Visibility BrowseButtonVisibility { get; set; }
        public Visibility SendButtonVisibility { get; set; }

        public ICommand BrowseButtonClick => new SharedComponents.DelegateCommand(browseButton_Click);

        public ICommand SendButtonClick => new SharedComponents.DelegateCommand(sendButton_Click);
        
        private void browseButton_Click()
        {
            var dialog = new OpenFileDialog();
            if (dialog.ShowDialog(null).GetValueOrDefault())
            {
                SelectedFile = dialog.FileName;
            }
        }

        private void sendButton_Click()
        {
            Client.UploadFile();
        }

        /// <summary>
        /// Hides or shows all buttons.
        /// </summary>
        /// <param name="visiblity">Parameter that determines whether buttons should be shown or hidden.</param>
        public void AlterButtonsVisibility(bool visiblity)
        {
            if (visiblity)
            {
                BrowseButtonVisibility = Visibility.Visible;
                SendButtonVisibility = Visibility.Visible;
            }
            else
            {
                BrowseButtonVisibility = Visibility.Hidden;
                SendButtonVisibility = Visibility.Hidden;
            }
        }
    }
}
