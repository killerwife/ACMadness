
namespace SharedComponents
{
    /// <summary>
    /// Class implements a simple symmetric encryption algorithm
    /// </summary>
    public class SimpleEncryption : IEncrypt
    {
        /// <summary>
        /// Encrypts message using simple method.
        /// Key character value is added to all characters in the following pattern:
        /// key=123
        /// text=123456
        /// result=1+1,2+2,3+3,1+4,2+5,3+6
        /// </summary>
        /// <param name="plainText"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public string EncryptMessage(string plainText, string key)
        {
            if (string.IsNullOrEmpty(key))
            {
                return plainText;
            }
            string output = "";
            for (int i = 0,k=0; i < plainText.Length;i++,k++)
            {
                if (k >= key.Length)
                {
                    k = 0;
                }
                output+=(char)(plainText[i] + key[k]);
            }
            return output;
        }

        /// <summary>
        /// Decryption using simple algorithm, which is direct reversal of encryption.
        /// </summary>
        /// <param name="cipherText"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public string DecryptMessage(string cipherText, string key)
        {
            if (string.IsNullOrEmpty(key))
            {
                return cipherText;
            }
            string output = "";
            for (int i = 0, k = 0; i < cipherText.Length; i++, k++)
            {
                if (k >= key.Length)
                {
                    k = 0;
                }
                output += (char)(cipherText[i] - key[k]);
            }
            return output;
        }
    }
}
