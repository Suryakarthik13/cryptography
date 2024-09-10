#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int p_len = strlen(plaintext);
    int k_len = strlen(key);
    int j = 0;

    for (int i = 0; i < p_len; i++) {
        if (isalpha(plaintext[i])) {
            char p_char = toupper(plaintext[i]);
            char k_char = toupper(key[j % k_len]);
            char c_char = ((p_char - 'A') + (k_char - 'A')) % 26 + 'A';
            ciphertext[i] = c_char;
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[p_len] = '\0'; 
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int c_len = strlen(ciphertext);
    int k_len = strlen(key);
    int j = 0;

    for (int i = 0; i < c_len; i++) {
        if (isalpha(ciphertext[i])) {
            char c_char = toupper(ciphertext[i]);
            char k_char = toupper(key[j % k_len]);
            char p_char = ((c_char - 'A') - (k_char - 'A') + 26) % 26 + 'A';
            plaintext[i] = p_char;
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[c_len] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decryptedtext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
