#include <stdio.h>

int main() {
    // Example key and subkeys (simplified)
    unsigned char key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    
    printf("Key: ");
    for (int i = 0; i < 8; i++) {
        printf("%02x ", key[i]);
    }
    printf("\n");
    
    // Generate and print subkeys (simplified)
    for (int i = 0; i < 16; i++) {
        printf("Subkey %2d: ", i + 1);
        for (int j = 0; j < 6; j++) {
            printf("%02x ", key[j]);
        }
        printf("\n");
    }
    
    return 0;
}

