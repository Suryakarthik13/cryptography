#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define TEXT_LENGTH 100

int main() {
    // Example ciphertext
    char ciphertext[] = "vhfinb dqmtk zkr gjqc";
    int length = strlen(ciphertext);
    int freq[ALPHABET_SIZE] = {0};
    
    // Count letter frequencies
    for (int i = 0; i < length; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            freq[ciphertext[i] - 'a']++;
        }
    }
    
    // Print frequencies
    printf("Letter frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }
    
    return 0;
}

