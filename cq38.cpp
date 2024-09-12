#include <stdio.h>
#include <string.h>
#include <ctype.h>

// English letter frequencies in descending order
const char ENGLISH_FREQ[] = "etaoinshrdlcumwfgypbvkjxqz";

// Function to calculate the frequency of each letter in the text
void calculate_frequencies(const char *text, int *frequencies) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            frequencies[toupper(text[i]) - 'A']++;
        }
    }
}

// Function to decrypt using a given key (shift value)
void decrypt_with_key(const char *ciphertext, int key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (ciphertext[i] - base - key + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabet characters are copied as is
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

// Function to rank shifts based on letter frequency
void rank_shifts(const char *ciphertext, int *ranked_shifts) {
    int shift_frequencies[26] = {0};
    char decrypted_text[1000];

    // Try all 26 possible shifts and calculate frequency match score
    for (int shift = 0; shift < 26; shift++) {
        int frequencies[26] = {0};
        decrypt_with_key(ciphertext, shift, decrypted_text);
        calculate_frequencies(decrypted_text, frequencies);

        // Calculate a rough score based on the correspondence to the expected English frequency
        for (int i = 0; i < 26; i++) {
            char most_common_letter = ENGLISH_FREQ[i];
            shift_frequencies[shift] += frequencies[most_common_letter - 'a'];
        }
    }

    // Rank shifts by frequency score
    for (int i = 0; i < 26; i++) {
        ranked_shifts[i] = i;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (shift_frequencies[ranked_shifts[i]] < shift_frequencies[ranked_shifts[j]]) {
                int temp = ranked_shifts[i];
                ranked_shifts[i] = ranked_shifts[j];
                ranked_shifts[j] = temp;
            }
        }
    }
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

    int ranked_shifts[26] = {0};
    char plaintext[1000];

    // Rank all shifts based on letter frequencies
    rank_shifts(ciphertext, ranked_shifts);

    // Generate the top N plaintexts based on ranked shifts
    for (int i = 0; i < num_plaintexts && i < 26; i++) {
        int shift = ranked_shifts[i];
        decrypt_with_key(ciphertext, shift, plaintext);
        printf("Plaintext attempt #%d (Shift = %d): %s\n", i + 1, shift, plaintext);
    }

    return 0;
}

