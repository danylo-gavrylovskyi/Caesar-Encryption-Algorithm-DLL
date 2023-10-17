#include <iostream>
#include <windows.h>

using namespace std;

int main() {

    HINSTANCE handle = LoadLibrary(TEXT("encryption.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return -1;
    }

    typedef void (*encrypt_ptr)(char*, int);
    encrypt_ptr encrypt = (encrypt_ptr)GetProcAddress(handle, "encrypt");
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    typedef void (*decrypt_ptr)(char*, int);
    decrypt_ptr decrypt = (decrypt_ptr)GetProcAddress(handle, "decrypt");
    if (decrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    int choice;

    while (true) {
        cout << "Choose the command:\n\t1 - encrypt\n\t2 - decrypt" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: {
            char textToEncrypt[256];
            int key;
            cout << "Enter text to encrypt: ";
            cin.ignore();
            cin.getline(textToEncrypt, sizeof(textToEncrypt));
            cout << "Enter encryption key: ";
            cin >> key;
            encrypt(textToEncrypt, key);
            cout << "Encrypted text: " << textToEncrypt << endl;
            break;
        }
        case 2: {
            char textToDecrypt[256];
            int key;
            cout << "Enter text to decrypt: ";
            cin.ignore();
            cin.getline(textToDecrypt, sizeof(textToDecrypt));
            cout << "Enter encryption key: ";
            cin >> key;
            decrypt(textToDecrypt, key);
            cout << "Decrypted text: " << textToDecrypt << endl;
            break;
        }
        default:
            break;
        }
    }

    FreeLibrary(handle);
    return 0;
}
