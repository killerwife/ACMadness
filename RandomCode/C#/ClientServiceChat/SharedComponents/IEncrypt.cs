
namespace SharedComponents
{
    /// <summary>
    /// Interface for string encryption.
    /// </summary>
    interface IEncrypt
    {
        string EncryptMessage(string plainText, string key);
        string DecryptMessage(string cipherText, string key);
    }

    /// <summary>
    /// Enum of implemented cyphers in project
    /// </summary>
    public enum Cyphers
    {
        SimpleEncryption,Rijndael
    }
}
