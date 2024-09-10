#include <stdio.h>

int main() {
    // Example key schedule
    int keys[16] = {0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78, 0x87, 0x96, 0xa5, 0xb4, 0xc3, 0xd2, 0xe1};
    
    // Example ciphertext
    int ciphertext = 0x01234567;  // Example 32-bit ciphertext
    int decrypted = ciphertext;
    
    // Reverse key order for decryption
    for (int i = 15; i >= 0; i--) {
        // Simulate decryption (not actual DES decryption)
        decrypted ^= keys[i];
    }
    
    // Print decrypted value
    printf("Decrypted text: 0x%08x\n", decrypted);
    
    return 0;
}

