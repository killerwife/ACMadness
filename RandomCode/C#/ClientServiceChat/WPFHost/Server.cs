using System;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace WPFHost
{
    class Server
    {
        private ServiceHost _host;

        /// <summary>
        /// Starts server, sets properties and initialises service.
        /// </summary>
        /// <param name="ip">IP on which server will start</param>
        /// <param name="port">Port on which the service will run and listen.</param>
        /// <returns></returns>
        public string Start(string ip,string port)
        {
            //Define base addresses so all endPoints can go under it

            Uri tcpAdrs = new Uri("net.tcp://" + ip + ":" +
                port + "/WPFHost/");
            //http protocol will run on address + 1111, reasoning: at home I have port forwarded 2 ports 7777 and 8888 :D
            Uri httpAdrs = new Uri("http://" + ip + ":" +
                (int.Parse(port) + 1111) + "/WPFHost/");

            Uri[] baseAdresses = { tcpAdrs,httpAdrs};

            _host = new ServiceHost(typeof(SharedComponents.ChatService), baseAdresses);


           /* NetTcpBinding tcpBinding = new NetTcpBinding(SecurityMode.None, true)
            {
                MaxBufferPoolSize = 67108864,
                MaxBufferSize = 67108864,
                MaxReceivedMessageSize = 67108864,
                TransferMode = TransferMode.Streamed,
                ReaderQuotas =
                {
                    MaxArrayLength = 67108864,
                    MaxBytesPerRead = 67108864,
                    MaxStringContentLength = 67108864
                },
                MaxConnections = 100
            };*/
            //Updated: to enable text transefer of 64 MB
            NetTcpBinding tcpBinding=new NetTcpBinding("tcpBinding");
            BasicHttpBinding httpBinding=new BasicHttpBinding("httpBinding");
            //To maxmize MaxConnections you have to assign another port for mex endpoint

            //and configure ServiceThrottling as well
            var throttle = _host.Description.Behaviors.Find<ServiceThrottlingBehavior>();
            if (throttle == null)
            {
                throttle = new ServiceThrottlingBehavior
                {
                    MaxConcurrentCalls = 100,
                    MaxConcurrentSessions = 100
                };
                _host.Description.Behaviors.Add(throttle);
            }


            //Enable reliable session and keep the connection alive for 20 hours.


            _host.AddServiceEndpoint(typeof(SharedComponents.IChat), tcpBinding, "tcp");
            _host.AddServiceEndpoint(typeof(SharedComponents.IFileTransferService), httpBinding, "http");

            //Define Metadata endPoint, So we can publish information about the service
            /*ServiceMetadataBehavior mBehave = new ServiceMetadataBehavior();
            _host.Description.Behaviors.Add(mBehave);

            _host.AddServiceEndpoint(typeof(IMetadataExchange),
                MetadataExchangeBindings.CreateMexTcpBinding(),
                "net.tcp://" + ip + ":" +
                (int.Parse(port)-1111) + "/WPFHost/mex");*/

            string output = "";
            try
            {
                _host.Open();
            }
            catch (Exception ex)
            {
                output= ex.Message;
            }
            finally
            {
                if (_host.State == CommunicationState.Opened)
                {
                    
                }
                else
                {
                    //mandatory "never get here" return value
                    output += "bla";
                }
            }
            return output;
        }

        /// <summary>
        /// Stops server and service
        /// </summary>
        /// <returns></returns>
        public string Stop()
        {
            string output = "";
            if (_host != null)
            {
                try
                {
                    _host.Close();
                }
                catch (Exception ex)
                {
                    output = ex.Message;
                }
                finally
                {
                    if (_host.State == CommunicationState.Closed)
                    {
                        
                    }
                    else
                    {
                        //mandatory "never get here" return value
                        output += "bla";
                    }
                }
            }
            return output;
        }
    }
}
