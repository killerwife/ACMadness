using System;
using System.Windows.Input;

namespace SharedComponents
{
    /// <summary>
    /// Implements DelegateCommand for GUI operations
    /// </summary>
    public class DelegateCommand : ICommand
    {
        private readonly Action _action;

        public DelegateCommand(Action action)
        {
            _action = action;
        }

        public void Execute(object parameter)
        {
            _action();
        }

        public bool CanExecute(object parameter)
        {
            //Instead of disabling button functionality, I opt for executing an explanation instead of disabling it entirely.
            return true;
        }

#pragma warning disable 67
        public event EventHandler CanExecuteChanged;
#pragma warning restore 67
    }
}
