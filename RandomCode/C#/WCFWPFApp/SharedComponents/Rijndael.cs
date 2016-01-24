using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace SharedComponents
{
    /// <summary>
    /// Class implements string encryption using Rijndael algorithm found in Cryptography namespace
    /// </summary>
    public class Rijndael : IEncrypt
    {
        private static readonly byte[] Salt = { 0x26, 0xdc, 0xff, 0x00, 0xad, 0xed, 0x7a, 0xee, 0xc5, 0xfe, 0x07, 0xaf, 0x4d, 0x08, 0x22, 0x3c };

        /// <summary>
        /// Encrypts message using RijndaelManaged class
        /// </summary>
        /// <param name="plainText">Text for encryption</param>
        /// <param name="key"></param>
        /// <returns></returns>
        public string EncryptMessage(string plainText, string key)
        {
            // Instantiate a new RijndaelManaged object to perform string symmetric encryption
            RijndaelManaged rijndaelCipher = new RijndaelManaged();

            Rfc2898DeriveBytes pdb = new Rfc2898DeriveBytes(key, Salt);
            // Set key and IV
            rijndaelCipher.Key = pdb.GetBytes(32);
            rijndaelCipher.IV = pdb.GetBytes(16);

            // Instantiate a new MemoryStream object to contain the encrypted bytes
            MemoryStream memoryStream = new MemoryStream();

            // Instantiate a new encryptor from our RijndaelManaged object
            ICryptoTransform rijndaelEncryptor = rijndaelCipher.CreateEncryptor();

            // Instantiate a new CryptoStream object to process the data and write it to the 
            // memory stream
            CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndaelEncryptor, CryptoStreamMode.Write);

            // Convert the plainText string into a byte array
            byte[] plainBytes = Encoding.ASCII.GetBytes(plainText);

            // Encrypt the input plaintext string
            cryptoStream.Write(plainBytes, 0, plainBytes.Length);

            // Complete the encryption process
            cryptoStream.FlushFinalBlock();

            // Convert the encrypted data from a MemoryStream to a byte array
            byte[] cipherBytes = memoryStream.ToArray();

            // Close both the MemoryStream and the CryptoStream
            memoryStream.Close();
            cryptoStream.Close();

            // Convert the encrypted byte array to a base64 encoded string
            string cipherText = Convert.ToBase64String(cipherBytes, 0, cipherBytes.Length);

            // Return the encrypted data as a string
            return cipherText;
        }

        /// <summary>
        /// Encrypts message using RijndaelManaged class
        /// </summary>
        /// <param name="cipherText">Text for decryption</param>
        /// <param name="key"></param>
        /// <returns></returns>
        public string DecryptMessage(string cipherText, string key)
        {
            // Instantiate a new RijndaelManaged object to perform string symmetric encryption
            RijndaelManaged rijndaelCipher = new RijndaelManaged();

            Rfc2898DeriveBytes pdb = new Rfc2898DeriveBytes(key, Salt);
            // Set key and IV
            rijndaelCipher.Key = pdb.GetBytes(32);
            rijndaelCipher.IV = pdb.GetBytes(16);

            // Instantiate a new MemoryStream object to contain the encrypted bytes
            MemoryStream memoryStream = new MemoryStream();

            // Instantiate a new encryptor from our RijndaelManaged object
            ICryptoTransform rijndaelDecryptor = rijndaelCipher.CreateDecryptor();

            // Instantiate a new CryptoStream object to process the data and write it to the 
            // memory stream
            CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndaelDecryptor, CryptoStreamMode.Write);

            // Will contain decrypted plaintext
            string plainText;

            try
            {
                // Convert the ciphertext string into a byte array
                byte[] cipherBytes = Convert.FromBase64String(cipherText);

                // Decrypt the input ciphertext string
                cryptoStream.Write(cipherBytes, 0, cipherBytes.Length);

                // Complete the decryption process
                cryptoStream.FlushFinalBlock();

                // Convert the decrypted data from a MemoryStream to a byte array
                byte[] plainBytes = memoryStream.ToArray();

                // Convert the encrypted byte array to a base64 encoded string
                plainText = Encoding.ASCII.GetString(plainBytes, 0, plainBytes.Length);
            }
            finally
            {
                // Close both the MemoryStream and the CryptoStream
                memoryStream.Close();
                cryptoStream.Close();
            }

            // Return the encrypted data as a string
            return plainText;
        }

    }
}
