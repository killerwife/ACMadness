//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace SharedComponents
{
    using System;
    using System.Collections.Generic;
    
    public partial class ChatData
    {
        public long Id { get; set; }
        public System.DateTime RecTime { get; set; }
        public string Message { get; set; }
        public long Sender { get; set; }
    
        public virtual ChatUsers ChatUsers { get; set; }
    }
}
