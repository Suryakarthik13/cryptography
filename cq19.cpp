#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    uint64_t key1 = 0x0123456789ABCDEF, key2 = 0x23456789ABCDEF01, key3 = 0x456789ABCDEF0123;
    uint64_t iv = 0xAABBCCDDEEFF0011;  // Initialization Vector
    uint64_t plaintext = 0x1234567890ABCDEF, ciphertext;

    // XOR with IV (CBC mode)
    uint64_t block = plaintext ^ iv;

    // Simulating 3DES Encryption
    block ^= key1;   // DES encryption step 1
    block ^= key2;   // DES encryption step 2 (decryption)
    ciphertext = block ^ key3;  // DES encryption step 3

    printf("Ciphertext: %016lx\n", ciphertext);
    return 0;
}
