#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Create repeating key of same length as text
string generateKey(string text, string keyword) {
    string key = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        key += keyword[j];
        j++;
        if (j == keyword.length()) {
            j = 0;
        }
    }
    return key;
}

// Encrypt the text
string encrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
        result += c;
    }
    return result;
}

// Decrypt the text
string decrypt(string cipher, string key) {
    string result = "";
    for (int i = 0; i < cipher.length(); i++) {
        char c = ((cipher[i] - key[i] + 26) % 26) + 'A';
        result += c;
    }
    return result;
}

int main() {
    string text = "SKYISPINK";
    string keyword = "AYUSH";

    // Make sure both are in uppercase
    for (int i = 0; i < text.length(); i++)
        text[i] = toupper(text[i]);

    for (int i = 0; i < keyword.length(); i++)
        keyword[i] = toupper(keyword[i]);

    string key = generateKey(text, keyword);
    string cipher = encrypt(text, key);
    string decrypted = decrypt(cipher, key);

    cout << "Plaintext  : " << text << endl;
    cout << "Key        : " << key << endl;
    cout << "Encrypted  : " << cipher << endl;
    cout << "Decrypted  : " << decrypted << endl;

    return 0;
}
