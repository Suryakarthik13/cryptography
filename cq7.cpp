#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define ALPHABET_SIZE 26

void calculate_frequency(const char *text, int freq[256]) {
    while (*text) {
        freq[(unsigned char)*text]++;
        text++;
    }
}

void print_frequency(int freq[256]) {
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("Character '%c': %d\n", i, freq[i]);
        }
    }
}

void decrypt_substitution(const char *ciphertext, const char *substitutions, char *decrypted_text) {
    while (*ciphertext) {
        if (*ciphertext >= '0' && *ciphertext <= '9') {
            decrypted_text += *ciphertext; // Keep non-alphabetic characters as they are
        } else {
            *decrypted_text = substitutions[(unsigned char)*ciphertext];
        }
        ciphertext++;
        decrypted_text++;
    }
    *decrypted_text = '\0';
}

int main() {
    char ciphertext[] = "531305))6:4826)41.)41);806°:48+8560))85:18*1*8+83 (88)5*1:46(188*96*7:8)(;485);5+2:*(:4956*2(5-4)858 4069285);)6+8)41:1(19:48081:8:811:48+85;4)485+528806*81 (19:48:(88:4(1734:48)4:161;:188:";
    int freq[256] = {0};
    int i;

    calculate_frequency(ciphertext, freq);

    printf("Character Frequencies:\n");
    print_frequency(freq);

    char substitutions[256];
    for (i = 0; i < 256; i++) {
        substitutions[i] = i; 
    }

    substitutions['5'] = 'e'; 
    substitutions['8'] = 't'; 
    substitutions['4'] = 'h'; 
    substitutions['1'] = 'a'; 

    char decrypted_text[MAX_TEXT_LENGTH];
    decrypt_substitution(ciphertext, substitutions, decrypted_text);

    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

