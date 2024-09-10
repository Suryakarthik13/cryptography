#include <stdio.h>

#define SIZE 2

int main() {
    // Define the key matrix (for simplicity, hardcoded values)
    int key[SIZE][SIZE] = {{6, 24}, {1, 8}};
    int inverse[SIZE][SIZE];
    int determinant;
    int invDet;
    
    // Example ciphertext and plaintext pairs
    char plaintext[SIZE] = {'d', 'e'};  // Example plaintext letters
    char ciphertext[SIZE] = {'m', 'o'}; // Example ciphertext letters
    
    // Calculate determinant
    determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    if (determinant == 0) {
        printf("Matrix is singular and cannot be inverted.\n");
        return 1;
    }
    
    // Calculate modular inverse of the determinant
    int mod = 26;
    // To find modular inverse, we need to use Extended Euclidean Algorithm or a pre-computed value
    invDet = 1; // For this example, we use 1 (assuming determ inant is 1 mod 26)
    while ((determinant * invDet) % mod != 1) {
        invDet++;
        if (invDet > 25) {
            printf("No modular inverse found.\n");
            return 1;
        }
    }
    
    // Calculate inverse matrix (modulo 26)
    inverse[0][0] = (key[1][1] * invDet) % mod;
    inverse[0][1] = (-key[0][1] * invDet) % mod;
    inverse[1][0] = (-key[1][0] * invDet) % mod;
    inverse[1][1] = (key[0][0] * invDet) % mod;

    // Ensure all values are positive
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (inverse[i][j] < 0) {
                inverse[i][j] += mod;
            }
        }
    }
    
    // Decrypt ciphertext
    char decrypted[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int row0 = (inverse[0][0] * (ciphertext[0] - 'a') + inverse[0][1] * (ciphertext[1] - 'a')) % mod;
        int row1 = (inverse[1][0] * (ciphertext[0] - 'a') + inverse[1][1] * (ciphertext[1] - 'a')) % mod;
        decrypted[0] = (row0 + mod) % mod + 'a';
        decrypted[1] = (row1 + mod) % mod + 'a';
    }
    
    // Print decrypted text
    printf("Decrypted text: %c%c\n", decrypted[0], decrypted[1]);
    
    return 0;
}

