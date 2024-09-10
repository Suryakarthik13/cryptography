#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void encrypt(char *plaintext, char *key, char *ciphertext) {
    for(int i = 0; plaintext[i] != '\0'; ++i) {
        char ch = plaintext[i];
        
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int index = toupper(ch) - 'A';
            ciphertext[i] = isupper(ch) ? toupper(key[index]) : tolower(key[index]);
        } else {
            ciphertext[i] = ch;  
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; 
}

int isValidKey(char *key) {
    int letterCount[ALPHABET_SIZE] = {0};
    for(int i = 0; key[i] != '\0'; ++i) {
        if (!isalpha(key[i])) {
            return 0;  
        }
        
        int index = toupper(key[i]) - 'A';
        letterCount[index]++;
    }

    for(int i = 0; i < ALPHABET_SIZE; ++i) {
        if (letterCount[i] != 1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char plaintext[100];
    char key[ALPHABET_SIZE + 1];
    char ciphertext[100];

    printf("Enter a string to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter a 26-character key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    if(strlen(key) != ALPHABET_SIZE || !isValidKey(key)) {
        printf("Invalid key! Please provide a 26-character key with unique alphabetic characters.\n");
        return 1;
    }

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
