#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generate_random_key(int *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % ALPHABET_SIZE;
    }
}

void vigenere_encrypt(const char *plaintext, const int *key, int key_length, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            int shift = key[i % key_length];
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + shift) % ALPHABET_SIZE) + 'A';
            } else {
                ciphertext[i] = ((plaintext[i] - 'a' + shift) % ALPHABET_SIZE) + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
        i++;
    }
    ciphertext[i] = '\0';
}

void vigenere_decrypt(const char *ciphertext, const int *key, int key_length, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (isalpha(ciphertext[i])) {
            int shift = key[i % key_length];
            if (isupper(ciphertext[i])) {
                plaintext[i] = ((ciphertext[i] - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
            } else {
                plaintext[i] = ((ciphertext[i] - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + 'a';
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
        i++;
    }
    plaintext[i] = '\0';
}

int main() {
    srand(time(NULL));
    
    const char *message = "Hello World";
    int key_length = 5;
    int key[key_length];
    char encrypted_message[100];
    char decrypted_message[100];

    generate_random_key(key, key_length);

    printf("Key: ");
    for (int i = 0; i < key_length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    vigenere_encrypt(message, key, key_length, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    vigenere_decrypt(encrypted_message, key, key_length, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

