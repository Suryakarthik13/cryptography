#include <stdio.h>
#include <string.h>

int main() {
    // 5x5 Playfair matrix
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'J'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    
    // Plain text to encrypt (without punctuation)
    char plaintext[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    
    // Prepare encrypted message
    char encrypted[256];
    int length = strlen(plaintext);
    int i, row1, row2, col1, col2;
    
    // Loop through pairs of plaintext letters
    for (i = 0; i < length; i += 2) {
        // Find positions of the first and second letters in the Playfair matrix
        for (row1 = 0; row1 < 5; row1++) {
            for (col1 = 0; col1 < 5; col1++) {
                if (matrix[row1][col1] == plaintext[i]) break;
            }
            if (col1 < 5) break;
        }
        for (row2 = 0; row2 < 5; row2++) {
            for (col2 = 0; col2 < 5; col2++) {
                if (matrix[row2][col2] == plaintext[i+1]) break;
            }
            if (col2 < 5) break;
        }

        // Apply Playfair encryption rules:
        if (row1 == row2) {
            // Same row: move right
            encrypted[i] = matrix[row1][(col1 + 1) % 5];
            encrypted[i+1] = matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            // Same column: move down
            encrypted[i] = matrix[(row1 + 1) % 5][col1];
            encrypted[i+1] = matrix[(row2 + 1) % 5][col2];
        } else {
            // Rectangle: swap columns
            encrypted[i] = matrix[row1][col2];
            encrypted[i+1] = matrix[row2][col1];
        }
    }

    encrypted[length] = '\0';  // Null-terminate the encrypted message
    
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}

