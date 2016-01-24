using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using ViewModel;

namespace WPFClient
{
    /// <summary>
    /// Interaction logic for HostWindow.xaml
    /// </summary>
    public partial class ClientWindow
    {
        /// <summary>
        /// Initialises GUI and assigns some GUI events that cant be bound with bindings
        /// </summary>
        public ClientWindow()
        {
            InitializeComponent();
            var dataContext = DataContext as ClientViewModel;
            if (dataContext != null)
            {
                dataContext.SetFocusAction(FocusChatWindow);
                dataContext.SetScrollDownAction(ScrollDown);
                Loaded += dataContext.Window_Loaded;
                Closing += dataContext.OnClosing;
                ChatTxtBoxType.KeyDown += dataContext.chatTxtBoxType_KeyDown;
                ChatTxtBoxType.KeyUp += dataContext.chatTxtBoxType_KeyUp;
            }
        }

        /// <summary>
        /// Function that focuses chat text box.
        /// </summary>
        public void FocusChatWindow()
        {
            ChatTxtBoxType.Focus();
        }

        /// <summary>
        /// This method to enable us scrolling the list box of messages
        /// when a new message comes from the service..
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        private ScrollViewer FindVisualChild(DependencyObject obj)
        {
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(obj); i++)
            {
                DependencyObject child = VisualTreeHelper.GetChild(obj, i);
                var viewer = child as ScrollViewer;
                if (viewer != null)
                {
                    return viewer;
                }
                else
                {
                    ScrollViewer childOfChild = FindVisualChild(child);
                    if (childOfChild != null)
                    {
                        return childOfChild;
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// Function that scrolls down one line in chat messages.
        /// </summary>
        public void ScrollDown()
        {
             ScrollViewer sv = FindVisualChild(ChatListBoxMsgs);
             sv.LineDown();
        }
    }
}
