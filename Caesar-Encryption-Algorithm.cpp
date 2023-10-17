#include <iostream>
#include <cstring>

extern "C" {
    __declspec(dllexport) void encrypt(char* rawText, int key) {
        for (int i = 0; rawText[i] != '\0'; i++) {
            if (isalpha(rawText[i])) {
                char base = isupper(rawText[i]) ? 'A' : 'a';
                rawText[i] = (char)(((rawText[i] - base + key) % 26) + base);
            }
        }
    }

    __declspec(dllexport) void decrypt(char* encryptedText, int key) {
        for (int i = 0; encryptedText[i] != '\0'; i++) {
            if (isalpha(encryptedText[i])) {
                char base = isupper(encryptedText[i]) ? 'A' : 'a';
                encryptedText[i] = (char)(((encryptedText[i] - base - key + 26) % 26) + base);
            }
        }
    }
}
