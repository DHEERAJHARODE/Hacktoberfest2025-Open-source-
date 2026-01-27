#include <stdio.h>
#include <string.h>

// XOR encryption/decryption
void xor_cipher(char *data, const char *key) {
    size_t data_len = strlen(data);
    size_t key_len = strlen(key);

    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];  // XOR each byte with the key
    }
}

int main() {
    char message[256];
    char key[256];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; 

    printf("Enter an encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    xor_cipher(message, key);
    printf("Encrypted message (hex): ");
    for (size_t i = 0; i < strlen(message); i++) {
        printf("%02X ", (unsigned char)message[i]);
    }
    printf("\n");

    // Decrypt the message (XOR again with same key)
    xor_cipher(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}