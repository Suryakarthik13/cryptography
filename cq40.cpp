#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// English letter frequencies in descending order
const char ENGLISH_FREQ[] = "etaoinshrdlcumwfgypbvkjxqz";

// Function to calculate letter frequencies in the given text
void calculate_frequencies(const char *text, int *frequencies) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            frequencies[toupper(text[i]) - 'A']++;
        }
    }
}

// Function to sort letters by frequency
void sort_by_frequency(const int *frequencies, char *sorted_letters) {
    int used[26] = {0}; // Track used letters
    for (int i = 0; i < 26; i++) {
        int max_idx = -1;
        int max_val = -1;
        for (int j = 0; j < 26; j++) {
            if (!used[j] && frequencies[j] > max_val) {
                max_val = frequencies[j];
                max_idx = j;
            }
        }
        if (max_idx != -1) {
            sorted_letters[i] = 'A' + max_idx;
            used[max_idx] = 1;
        }
    }
}

// Function to decrypt using the given letter mapping
void decrypt(const char *ciphertext, const char *map, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char upper = toupper(ciphertext[i]);
            char decrypted_char = map[upper - 'A'];
            plaintext[i] = islower(ciphertext[i]) ? tolower(decrypted_char) : decrypted_char;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

// Main function
int main() {
    char ciphertext[1000];
    int num_plaintexts;

    // Input ciphertext and number of desired plaintexts
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    printf("Enter the number of plaintexts you want: ");
    scanf("%d", &num_plaintexts);

    // Remove newline character from the ciphertext
    ciphertext[strcspn(ciphertext, "\n")] = 0;

    int frequencies[26] = {0};
    char sorted_letters[27] = {0};
    char map[26] = {0};
    char plaintext[1000] = {0};

    // Calculate letter frequencies of ciphertext
    calculate_frequencies(ciphertext, frequencies);

    // Sort letters by frequency in the ciphertext
    sort_by_frequency(frequencies, sorted_letters);

    // Generate potential plaintexts
    for (int i = 0; i < num_plaintexts; i++) {
        // Create a letter mapping based on the i-th shift in the frequency
        for (int j = 0; j < 26; j++) {
            map[sorted_letters[j] - 'A'] = ENGLISH_FREQ[(j + i) % 26];
        }

        // Decrypt using the current map
        decrypt(ciphertext, map, plaintext);

        // Display the current attempt
        printf("Plaintext attempt #%d: %s\n", i + 1, plaintext);
    }

    return 0;
}

