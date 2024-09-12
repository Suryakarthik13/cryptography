#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_PLAINTEXTS 10

// Frequencies of letters in English
const double letter_freq[ALPHABET_SIZE] = {
    0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.001,
    0.005, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.061, 0.060, 0.091,
    0.028, 0.010, 0.023, 0.001, 0.020, 0.001, 0.002, 0.053, 0.016, 0.010
};

// Function to calculate letter frequency in the ciphertext
void calculate_frequency(const char *text, double *freq) {
    int count[ALPHABET_SIZE] = {0};
    int length = 0;

    while (*text) {
        if (isalpha(*text)) {
            count[toupper(*text) - 'A']++;
            length++;
        }
        text++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freq[i] = (double)count[i] / length;
    }
}

// Function to score the plaintext based on letter frequency
double score_plaintext(const double *freq) {
    double score = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        score += (freq[i] - letter_freq[i]) * (freq[i] - letter_freq[i]);
    }
    return score;
}

// Function to decrypt with a given substitution cipher
void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            plaintext[*ciphertext - 'A'] = key[*ciphertext - 'A'];
        } else {
            plaintext[*ciphertext] = *ciphertext;
        }
        ciphertext++;
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[] = "CIPHERTEXTEXAMPLE";
    char key[ALPHABET_SIZE + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char plaintext[256];
    double freq[ALPHABET_SIZE];

    calculate_frequency(ciphertext, freq);

    // Simple substitution for demonstration
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        key[i] = 'A' + i;
    }
    
    decrypt(ciphertext, key, plaintext);
    printf("Possible plaintext: %s\n", plaintext);

    return 0;
}

