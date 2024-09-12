#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define AES_BLOCK_SIZE 16

void shift_left_and_xor(uint8_t *block, uint8_t *result, uint8_t constant) {
    int carry = 0;
    for (int i = AES_BLOCK_SIZE - 1; i >= 0; i--) {
        int new_carry = (block[i] & 0x80) ? 1 : 0;
        result[i] = (block[i] << 1) | carry;
        carry = new_carry;
    }
    if (carry) {
        result[0] ^= constant;
    }
}

// Simulated AES encryption (not a real AES encryption for simplicity)
void aes_encrypt(const uint8_t *key, const uint8_t *input, uint8_t *output) {
    memcpy(output, input, AES_BLOCK_SIZE);  // Simulated encryption (no real encryption)
}

void generate_subkeys(const uint8_t *key, uint8_t *k1, uint8_t *k2) {
    uint8_t block[AES_BLOCK_SIZE] = {0};
    uint8_t result[AES_BLOCK_SIZE];
    
    aes_encrypt(key, block, result);
    
    shift_left_and_xor(result, k1, 0x87);  // constant for 128-bit block
    
    shift_left_and_xor(k1, k2, 0x87);  // constant for 128-bit block
}

void print_block(const uint8_t *block) {
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", block[i]);
    }
    printf("\n");
}

int main() {
    uint8_t key[AES_BLOCK_SIZE] = {0};  // Example key
    uint8_t k1[AES_BLOCK_SIZE];
    uint8_t k2[AES_BLOCK_SIZE];

    generate_subkeys(key, k1, k2);
    
    printf("K1: ");
    print_block(k1);
    
    printf("K2: ");
    print_block(k2);

    return 0;
}

