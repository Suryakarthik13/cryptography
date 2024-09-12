#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No modular inverse exists
}

void affine_encrypt(const char *plaintext, char *ciphertext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int offset = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (a * (plaintext[i] - offset) + b) % ALPHABET_SIZE + offset;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(*plaintext)] = '\0';
}

void affine_decrypt(const char *ciphertext, char *plaintext, int a, int b) {
    int a_inv = mod_inverse(a, ALPHABET_SIZE);
    if (a_inv == -1) {
        printf("No modular inverse exists for the given 'a' value.\n");
        return;
    }

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            int offset = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = a_inv * (ciphertext[i] - offset - b + ALPHABET_SIZE) % ALPHABET_SIZE + offset;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    const char *message = "Hello World";
    int a = 5;
    int b = 8;
    char encrypted_message[100];
    char decrypted_message[100];

    affine_encrypt(message, encrypted_message, a, b);
    printf("Encrypted message: %s\n", encrypted_message);

    affine_decrypt(encrypted_message, decrypted_message, a, b);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

