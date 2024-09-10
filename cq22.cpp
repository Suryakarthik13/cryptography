#include <stdio.h>

#define BLOCK_SIZE 8
#define PLAINTEXT_SIZE 16

// Main function for CBC encryption and decryption using S-DES
int main() {
    unsigned char key = 0b0111111101; // S-DES key
    unsigned char iv = 0b10101010; // Initialization Vector

    unsigned char plaintext[2] = {0b00000001, 0b00100011}; // Example binary plaintext
    unsigned char ciphertext[2];
    unsigned char decryptedtext[2];

    // CBC Encryption
    printf("CBC Mode Encryption using S-DES:\n");
    unsigned char prev_block = iv;

    for (int i = 0; i < 2; i++) {
        ciphertext[i] = (plaintext[i] ^ prev_block) ^ key; // Simplified S-DES step
        prev_block = ciphertext[i];
        printf("Ciphertext[%d]: %02X\n", i, ciphertext[i]);
    }

    // CBC Decryption
    printf("\nCBC Mode Decryption using S-DES:\n");
    prev_block = iv; // Reset IV

    for (int i = 0; i < 2; i++) {
        decryptedtext[i] = (ciphertext[i] ^ key) ^ prev_block;
        prev_block = ciphertext[i];
        printf("Decryptedtext[%d]: %02X\n", i, decryptedtext[i]);
    }

    return 0;
}

