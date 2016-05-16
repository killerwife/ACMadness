using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using PropertyChanged;
using WPFClient;
using WPFHost.Annotations;

namespace ViewModel
{
    /// <summary>
    /// View model that handles all ClientWindow functions.
    /// </summary>
    [ImplementPropertyChanged]
    class ClientViewModel : INotifyPropertyChanged
    {
        /// <summary>
        /// Client reference.
        /// </summary>
        readonly Client _client;
        //data members bound to properties
        private Action _focusChatWindow;
        private Action _scrollDown;
        private string _chatInputText;
        private ListBoxItem _chatNameSelected;
        FileTransferClient _fileWindow;
        public FtcViewModel FileWindowModel;

        /// <summary>
        /// Initialises some gui bound properties and lists
        /// </summary>
        public ClientViewModel()
        {
            _client = new Client(this);
            ForegroundColor = new SolidColorBrush(Colors.White);
            ConnectButtonIsEnabled = true;
            LoginComboBoxImgs=new ObservableCollection<ListBoxItem>();
            ChatNames=new ObservableCollection<ListBoxItem>();
            ChatMsgs=new ObservableCollection<ListBoxItem>();
            _chatInputText="";
            Name = "killerwife";
            ConnectionIP = "localhost:7777";
            Key = "bla";
        }

        //Properties and functions bound to GUI
        public ICommand ButtonDecrypt => new SharedComponents.DelegateCommand(buttonDecrypt_Click);

        public int SelectedCypher { get; set; }

        public string Key { get; set; }

        public string Name { get; set;
            //loginTxtBoxUName.Text
        }

        public ObservableCollection<ListBoxItem> LoginComboBoxImgs { get; set;
            //loginComboBoxImgs
        }

        public int SelectedIndex { get; set;
            //loginComboBoxImgs.SelectedIndex
        }

        public string ConnectionIP { get; set;
            //loginTxtBoxIP.Text
        }

        public string ChatStatusLabel { get; set;
            //chatLabelCurrentStatus
        }

        public string LoginStatusLabel { get; set;
            //loginLabelStatus.Content
        }

        public bool ConnectButtonIsEnabled { get; set;
            //loginButtonConnect.IsEnabled
        }

        public string ChatInputText
        {
            get { return _chatInputText; }
            set
            {
                _chatInputText = value;
                RaisePropertyChangedEvent(nameof(ChatInputText));
                _focusChatWindow();
            }
            //chatTxtBoxType.Text
            //chatTxtBoxType.Focus()
        }

        public bool WhisperBox { get; set;
            //(bool)chatCheckBoxWhisper.IsChecked
        }

        public Brush ForegroundColor { get; set;
            //loginLabelStatus.Foreground
        }

        public ListBoxItem ChatNameSelected
        {
            get { return _chatNameSelected; }
            set
            {
                _chatNameSelected = value;
                _client.chatListBoxNames_SelectionChanged();
                RaisePropertyChangedEvent(nameof(ChatNameSelected));
            }
            //chatListBoxNames.SelectedItem
        }

        public ObservableCollection<ListBoxItem> ChatNames { get; set;
            //chatListBoxNames
        }

        public ObservableCollection<ListBoxItem> ChatMsgs { get; set;
            //chatListBoxMsgs
        }

        public string LabelWritingMsg { get; set;
            //chatLabelWritingMsg.Content
        }

        public ImageSource CurrentImage { get; set;
            //chatCurrentImage
        }

        public Visibility LoginButtonConnectVisibility { get; set; }

        public Visibility LoginComboBoxImgsVisibility { get; set; }

        public Visibility LoginLabelIPVisibility { get; set; }

        public Visibility LoginLabelStatusVisibility { get; set; }

        public Visibility LoginLabelTitleVisibility { get; set; }

        public Visibility LoginLabelUNameVisibility { get; set; }

        public Visibility LoginPolyLineVisibility { get; set; }

        public Visibility LoginTxtBoxIPVisibility { get; set; }

        public Visibility LoginTxtBoxUNameVisibility { get; set; }

        public Visibility ChatButtonDisconnectVisibility { get; set; }

        public Visibility ChatButtonSendVisibility { get; set; }

        public Visibility ChatCheckBoxWhisperVisibility { get; set; }

        public Visibility ChatCurrentImageVisibility { get; set; }

        public Visibility ChatLabelCurrentStatusVisibility { get; set; }

        public Visibility ChatLabelCurrentUNameVisibility { get; set; }

        public Visibility ChatListBoxMsgsVisibility { get; set; }

        public Visibility ChatListBoxNamesVisibility { get; set; }

        public Visibility ChatTxtBoxTypeVisibility { get; set; }

        public Visibility ChatLabelWritingMsgVisibility { get; set; }

        public Visibility ChatSendFileVisibility { get; set; }

        public ICommand ButtonConnectClick => new SharedComponents.DelegateCommand(buttonConnect_Click);

        public ICommand ChatButtonSendClick => new SharedComponents.DelegateCommand(chatButtonSend_Click);

        public ICommand ChatButtonDisconnectClick => new SharedComponents.DelegateCommand(chatButtonDisconnect_Click);

        public ICommand ButtonOpenSendFileDialog => new SharedComponents.DelegateCommand(sendFileDialog_Click);

        //functions that execute button commands
        private void buttonDecrypt_Click()
        {
            _client.Decrypt();
        }

        private void buttonConnect_Click()
        {
            ConnectButtonIsEnabled = false;
            LoginStatusLabel = "Connecting..";
            _client.buttonConnect_Click();
        }

        private void chatButtonSend_Click()
        {
            _client.Send();
        }

        private void chatButtonDisconnect_Click()
        {
            _client.Disconnect();
        }

        /// <summary>
        /// Opens a send file dialog.
        /// </summary>
        private void sendFileDialog_Click()
        {
            _fileWindow = new FileTransferClient();
            FileWindowModel = _fileWindow.DataContext as FtcViewModel;
            if (FileWindowModel != null) FileWindowModel.Client = _client;
            _fileWindow.Show();
        }

        /// <summary>
        /// Opens progress window, that is opened when a file is received and hides all buttons.
        /// </summary>
        public void OpenProgressWindow()
        {
            _fileWindow = new FileTransferClient();
            FileWindowModel = _fileWindow.DataContext as FtcViewModel;
            if (FileWindowModel != null)
            {
                FileWindowModel.Client = _client;
                FileWindowModel.AlterButtonsVisibility(false);
            }
            _fileWindow.Show();
            _fileWindow.Activate();
        }

        /// <summary>
        /// Closes progress window, in case of different thread, invokes the action on the right thread.
        /// </summary>
        public void CloseProgressWindow()
        {
            // Make sure we're running on the UI thread
            if (!_fileWindow.CheckAccess())
            {
                _fileWindow.Dispatcher.BeginInvoke(new Action(CloseProgressWindow));
                return;
            }

            // Close the form now that we're running on the UI thread
            _fileWindow.Close();
        }

        /// <summary>
        /// Assigns action for focusing on chat text box
        /// </summary>
        /// <param name="a"></param>
        public void SetFocusAction(Action a)
        {
            _focusChatWindow = a;
        }

        /// <summary>
        /// Assigns action for scrolling down in chat
        /// </summary>
        /// <param name="a"></param>
        public void SetScrollDownAction(Action a)
        {
            _scrollDown = a;
        }

        /// <summary>
        /// GUI commands that need to be executed after closing a connection
        /// </summary>
        public void CloseConnection()
        {
            ChatMsgs.Clear();
            ChatNames.Clear();
            LoginStatusLabel = "Disconnected";
            ShowChat(false);
            ShowLogin(true);
            ConnectButtonIsEnabled = true;
        }

        /// <summary>
        /// GUI commands that need to be executed after opening a connection
        /// </summary>
        /// <param name="name">Name of user using client</param>
        /// <param name="images">Images of avatars</param>
        public void OpenConnection(string name, Dictionary<int, Image> images)
        {
            Image img = images[SelectedIndex];
            CurrentImage = img.Source;
            ShowLogin(false);
            ShowChat(true);
            ChatStatusLabel = "online";
        }

        /// <summary>
        /// Executes after main GUI window is loaded
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void Window_Loaded(object sender, RoutedEventArgs e)
        {
            Dictionary<int, Image> images = _client.GetImages();
            var temp=new ObservableCollection<ListBoxItem>();
            //Populate images in the login comboBoc control
            foreach (Image img in images.Values)
            {
                ListBoxItem item = new ListBoxItem
                {
                    Width = 90,
                    Height = 90,
                    Content = img
                };
                temp.Add(item);
            }
            LoginComboBoxImgs = temp;
            SelectedIndex = 0;
            ShowChat(false);
            ShowLogin(true);
        }

        /// <summary>
        /// Show or hide login controls depends on the parameter
        /// </summary>
        /// <param name="show"></param>
        private void ShowLogin(bool show)
        {
            if (show)
            {
                LoginButtonConnectVisibility = Visibility.Visible;
                LoginComboBoxImgsVisibility = Visibility.Visible;
                LoginLabelIPVisibility = Visibility.Visible;
                LoginLabelStatusVisibility = Visibility.Visible;
                LoginLabelTitleVisibility = Visibility.Visible;
                LoginLabelUNameVisibility = Visibility.Visible;
                LoginPolyLineVisibility = Visibility.Visible;
                LoginTxtBoxIPVisibility = Visibility.Visible;
                LoginTxtBoxUNameVisibility = Visibility.Visible;
            }
            else
            {
                LoginButtonConnectVisibility = Visibility.Collapsed;
                LoginComboBoxImgsVisibility = Visibility.Collapsed;
                LoginLabelIPVisibility = Visibility.Collapsed;
                LoginLabelStatusVisibility = Visibility.Collapsed;
                LoginLabelTitleVisibility = Visibility.Collapsed;
                LoginLabelUNameVisibility = Visibility.Collapsed;
                LoginPolyLineVisibility = Visibility.Collapsed;
                LoginTxtBoxIPVisibility = Visibility.Collapsed;
                LoginTxtBoxUNameVisibility = Visibility.Collapsed;
            }
        }


        /// <summary>
        /// Show or hide chat controls depends on the parameter
        /// </summary>
        /// <param name="show"></param>
        private void ShowChat(bool show)
        {
            if (show)
            {
                ChatSendFileVisibility=Visibility.Visible;
                ChatButtonDisconnectVisibility = Visibility.Visible;
                ChatButtonSendVisibility = Visibility.Visible;
                ChatCheckBoxWhisperVisibility = Visibility.Visible;
                ChatCurrentImageVisibility = Visibility.Visible;
                ChatLabelCurrentStatusVisibility = Visibility.Visible;
                ChatLabelCurrentUNameVisibility = Visibility.Visible;
                ChatListBoxMsgsVisibility = Visibility.Visible;
                ChatListBoxNamesVisibility = Visibility.Visible;
                ChatTxtBoxTypeVisibility = Visibility.Visible;
                ChatLabelWritingMsgVisibility = Visibility.Visible;
            }
            else
            {
                ChatSendFileVisibility = Visibility.Collapsed;
                ChatButtonDisconnectVisibility = Visibility.Collapsed;
                ChatButtonSendVisibility = Visibility.Collapsed;
                ChatCheckBoxWhisperVisibility = Visibility.Collapsed;
                ChatCurrentImageVisibility = Visibility.Collapsed;
                ChatLabelCurrentStatusVisibility = Visibility.Collapsed;
                ChatLabelCurrentUNameVisibility = Visibility.Collapsed;
                ChatListBoxMsgsVisibility = Visibility.Collapsed;
                ChatListBoxNamesVisibility = Visibility.Collapsed;
                ChatTxtBoxTypeVisibility = Visibility.Collapsed;
                ChatLabelWritingMsgVisibility = Visibility.Collapsed;
            }
        }

        /// <summary>
        /// Executes when main GUI window is closed.
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="e"></param>
        public void OnClosing(object obj,CancelEventArgs e)
        {
            _client.Disconnect();
        }

        //key events handling for chat text box 
        public void chatTxtBoxType_KeyUp(object sender, KeyEventArgs e)
        {
            _client.chatTxtBoxType_KeyUp();
        }

        public void chatTxtBoxType_KeyDown(object sender, KeyEventArgs e)
        {
            _client.chatTxtBoxType_KeyDown(e);
        }

        //Interface implementation for handling property changed events
        public event PropertyChangedEventHandler PropertyChanged;

        [NotifyPropertyChangedInvocator]
        protected void RaisePropertyChangedEvent(string propertyName)
        {
            var handler = PropertyChanged;
            handler?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        /// <summary>
        /// Function that executes assigned action for scrolling down in chat messages
        /// </summary>
        public void ScrollDown()
        {
            _scrollDown();
        }
    }
}
