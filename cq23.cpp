#include <stdio.h>

#define PLAINTEXT_SIZE 3 // For simplicity, 3 segments of plaintext

// Main function for Counter Mode using S-DES (without functions)
int main() {
    unsigned char key = 0b0111111101;        // S-DES key
    unsigned char counter = 0b00000000;      // Starting counter
    unsigned char plaintext[PLAINTEXT_SIZE] = {0b00000001, 0b00000010, 0b00000100}; // Binary plaintext
    unsigned char ciphertext[PLAINTEXT_SIZE];
    unsigned char decryptedtext[PLAINTEXT_SIZE];

    // Counter Mode Encryption
    printf("Counter Mode Encryption using S-DES:\n");

    for (int i = 0; i < PLAINTEXT_SIZE; i++) {
        ciphertext[i] = (counter ^ key) ^ plaintext[i]; // Counter XOR with key and plaintext
        printf("Ciphertext[%d]: %02X\n", i, ciphertext[i]);
        counter++; // Increment counter for the next block
    }

    // Reset counter for decryption
    counter = 0b00000000;

    // Counter Mode Decryption
    printf("\nCounter Mode Decryption using S-DES:\n");

    for (int i = 0; i < PLAINTEXT_SIZE; i++) {
        decryptedtext[i] = (counter ^ key) ^ ciphertext[i]; // Counter XOR with key and ciphertext
        printf("Decryptedtext[%d]: %02X\n", i, decryptedtext[i]);
        counter++; // Increment counter for the next block
    }

    return 0;
}

