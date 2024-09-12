#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 8

// Dummy DES encryption function
void des_encrypt_decrypt(const uint8_t *key, const uint8_t *input, uint8_t *output, int encrypt) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i];
    }
}

// ECB mode
void ecb_encrypt(const uint8_t *key, const uint8_t *plaintext, uint8_t *ciphertext) {
    des_encrypt_decrypt(key, plaintext, ciphertext, 1);
}

// CBC mode
void cbc_encrypt(const uint8_t *key, const uint8_t *plaintext, uint8_t *ciphertext, const uint8_t *iv) {
    uint8_t block[BLOCK_SIZE];
    uint8_t xor_block[BLOCK_SIZE];
    
    for (int i = 0; i < BLOCK_SIZE; i++) {
        xor_block[i] = plaintext[i] ^ iv[i];
    }
    
    des_encrypt_decrypt(key, xor_block, ciphertext, 1);
}

// CFB mode
void cfb_encrypt(const uint8_t *key, const uint8_t *plaintext, uint8_t *ciphertext, const uint8_t *iv) {
    uint8_t feedback[BLOCK_SIZE];
    memcpy(feedback, iv, BLOCK_SIZE);
    
    for (int i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp;
        des_encrypt_decrypt(key, feedback, feedback, 1);
        temp = plaintext[i] ^ feedback[0];
        ciphertext[i] = temp;
        memmove(feedback, feedback + 1, BLOCK_SIZE - 1);
        feedback[BLOCK_SIZE - 1] = temp;
    }
}

void print_block(const uint8_t *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", block[i]);
    }
    printf("\n");
}

int main() {
    uint8_t key[BLOCK_SIZE] = "12345678";
    uint8_t plaintext[BLOCK_SIZE] = "message";
    uint8_t ciphertext[BLOCK_SIZE];
    uint8_t decryptedtext[BLOCK_SIZE];
    uint8_t iv[BLOCK_SIZE] = {0};  // Initialization vector for CBC and CFB

    // ECB Mode
    ecb_encrypt(key, plaintext, ciphertext);
    printf("ECB Ciphertext: ");
    print_block(ciphertext);

    // CBC Mode
    cbc_encrypt(key, plaintext, ciphertext, iv);
    printf("CBC Ciphertext: ");
    print_block(ciphertext);

    // CFB Mode
    cfb_encrypt(key, plaintext, ciphertext, iv);
    printf("CFB Ciphertext: ");
    print_block(ciphertext);

    return 0;
}

