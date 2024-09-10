#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t plaintext1 = 0x1234567890ABCDEF, plaintext2 = 0xFEDCBA0987654321, key = 0xAABBCCDDEEFF0011, iv = 0x0123456789ABCDEF;
    uint64_t c1, c2, r1, r2, d1, d2;

    // ECB Mode Encryption and Decryption
    c1 = plaintext1 ^ key;  // Encrypt Block 1
    c2 = plaintext2 ^ key;  // Encrypt Block 2
    r1 = c1 ^ 0x1;          // Simulated error in transmission
    d1 = r1 ^ key;          // Decrypt Block 1 with error
    d2 = c2 ^ key;          // Decrypt Block 2 (no error)

    printf("ECB Mode Decrypted Block 1: %016lx\n", d1);
    printf("ECB Mode Decrypted Block 2: %016lx\n", d2);

    // CBC Mode Encryption and Decryption
    c1 = (plaintext1 ^ iv) ^ key;  // Encrypt Block 1 in CBC mode
    c2 = (plaintext2 ^ c1) ^ key;  // Encrypt Block 2 in CBC mode
    r1 = c1 ^ 0x1;                 // Simulated error in transmission
    d1 = (r1 ^ key) ^ iv;          // Decrypt Block 1 with error
    d2 = (c2 ^ key) ^ r1;          // Decrypt Block 2 with error propagation

    printf("CBC Mode Decrypted Block 1: %016lx\n", d1);
    printf("CBC Mode Decrypted Block 2: %016lx\n", d2);

    return 0;
}
