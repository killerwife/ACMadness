   M S B A M L   `   `   `  ����D  @WPFClient, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:ViewModel	ViewModel  5   	   "    WPFClient.FileTransferClient   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   )localclr-namespace:ViewModel     5   	     � Title$  FileTransferClient��5   	   $��154.709��6$   $��383.177��65    � DataContext 5	        ViewModel.FtcViewModel  5
   
   .��5      � ��5   
   �� 5      .��5      �  � Color$ LightSlateGray��6    � Offset$ 0Q�66   � 5      $ White��6   $	 0.5Q�6-   � 5      $ LightSlateGray��6   $	 0.9Q�66   5      .+�5   
   � -   5        $��PbStatus��5   �   $��25��6U    � Minimum$ 0Q�6a   $��	0,39,0,60q�6�   
���   � � Value 6   �� *
Progress+ �� UpdateSourceTrigger$ PropertyChanged=� � Maximum 6m   �� *ProgressMax+$ PropertyChanged=�6�   �� 5   
   -   5         ��Name$ BrowseButton��5      $��Browse��6�   $
��Left=�6�   $��	10,10,0,0q�6�   $	��Top=�6�   $��75��6�   ��6'   �� *BrowseButtonClick+y�6M   �� *BrowseButtonVisibility+$ PropertyChanged=�6�   �� 5   
   -   5        $ 
SendButton��5      $
��Send��6�   $
��Left=�6�   $��
151,10,0,0q�6�   $	��Top=�6�   $��75��6�   ��6%   �� *SendButtonClick+y�6I   �� *SendButtonVisibility+$ PropertyChanged=�6�   �� 5   
   -   5        	 ��Name$	 FileNameLabel��5      $
��Left=�6m   $��	10,69,0,0q�6�   $	��Top=�6�   $��95��6�   ��6'   �� *FileNameLabel+$ PropertyChanged=�6�   �� 5   
   -   5        $	 	DoneLabel��5      $
��Left=�6e   $��
151,69,0,0q�6�   $	��Top=�6�   $	��218��6�   $��24��6�   ��6#   �� *	DoneLabel+$ PropertyChanged=�6�   5      5      