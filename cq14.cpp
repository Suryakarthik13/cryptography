#include <stdio.h>

#define MAX_TEXT_LENGTH 100

int main() {
    // Example plaintext and key stream
    char plaintext[] = "send more money";
    int keyStream[] = {9, 0, 1, 7, 2, 3, 15, 21, 14, 11, 11, 28, 9};
    int keyLength = sizeof(keyStream) / sizeof(keyStream[0]);

    char ciphertext[MAX_TEXT_LENGTH];
    
    // Encrypt plaintext
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] == ' ') {
            ciphertext[i] = ' ';
        } else {
            int shift = keyStream[i % keyLength];
            ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
        }
    }
    
    // Null-terminate and print ciphertext
    ciphertext[strlen(plaintext)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}

