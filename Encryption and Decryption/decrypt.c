#include<stdio.h>
#include<string.h>

// Fungsi untuk mendekripsi pesan
void decrypt (char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = *ptr - 1; // Mengurangi nilai ASCII sebanyak 1
        ptr++;
    }
}

// Fungsi untuk mengenkripsi pesan
void encrypt (char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = *ptr + 1; // Menambah nilai ASCII sebanyak 1
        ptr++;
    }
}

int main() {
    char str[100]; // Array untuk menyimpan input pengguna
    int choice;

    // Loop untuk menjalankan program berulang kali
    do {
        printf("\nMenu:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer input

        switch (choice) {
            case 1:
                printf("Enter a string to encrypt: ");
                fgets(str, 100, stdin); // Mengambil input pengguna
                str[strcspn(str, "\n")] = '\0'; // Menghilangkan newline character
                encrypt(str);
                printf("Encrypted string: %s\n", str);
                break;
            case 2:
                printf("Enter a string to decrypt: ");
                fgets(str, 100, stdin); // Mengambil input pengguna
                str[strcspn(str, "\n")] = '\0'; // Menghilangkan newline character
                decrypt(str);
                printf("Decrypted string: %s\n", str);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3); // Looping sampai user memilih opsi keluar

    return 0;
}
