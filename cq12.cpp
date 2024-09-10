#include <stdio.h>
#include <string.h>

#define SIZE 2 // Size of the key matrix (2x2)

// Function to find the modular inverse of a number modulo 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to encrypt the message using Hill cipher
void hillEncrypt(int key[SIZE][SIZE], char plaintext[], char ciphertext[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i += 2) {
        int p1 = plaintext[i] - 'A';
        int p2 = plaintext[i+1] - 'A';
        
        // Hill cipher encryption formula
        ciphertext[i] = ((key[0][0] * p1 + key[0][1] * p2) % 26) + 'A';
        ciphertext[i+1] = ((key[1][0] * p1 + key[1][1] * p2) % 26) + 'A';
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext
}

// Function to decrypt the message using Hill cipher
void hillDecrypt(int inverseKey[SIZE][SIZE], char ciphertext[], char decryptedText[]) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i += 2) {
        int c1 = ciphertext[i] - 'A';
        int c2 = ciphertext[i+1] - 'A';
        
        // Hill cipher decryption formula
        decryptedText[i] = ((inverseKey[0][0] * c1 + inverseKey[0][1] * c2) % 26) + 'A';
        decryptedText[i+1] = ((inverseKey[1][0] * c1 + inverseKey[1][1] * c2) % 26) + 'A';
    }
    decryptedText[i] = '\0'; // Null terminate the decrypted text
}

// Helper function to prepare the plaintext (remove spaces, convert to uppercase)
void prepareText(char input[], char output[]) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[j++] = input[i] - 'a' + 'A'; // Convert to uppercase
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[j++] = input[i];
        }
    }
    if (j % 2 != 0) {
        output[j++] = 'X'; // Padding if odd number of characters
    }
    output[j] = '\0';
}

int main() {
    // Hill cipher key matrix
    int key[2][2] = {{9, 4}, {5, 7}};
    
    // Inverse key matrix (precomputed using modular arithmetic)
    int inverseKey[2][2] = {{7, 22}, {23, 9}};
    
    // Plaintext message
    char plaintext[] = "meet me at the usual place at ten rather than eight oclock";
    char preparedText[256];  // To store the processed text
    char ciphertext[256];    // To store the encrypted text
    char decryptedText[256]; // To store the decrypted text
    
    // Prepare the text (remove spaces, convert to uppercase)
    prepareText(plaintext, preparedText);
    
    // Encrypt the message
    hillEncrypt(key, preparedText, ciphertext);
    
    printf("Original plaintext: %s\n", preparedText);
    printf("Encrypted message: %s\n", ciphertext);
    
    // Decrypt the message
    hillDecrypt(inverseKey, ciphertext, decryptedText);
    
    printf("Decrypted message: %s\n", decryptedText);
    
    return 0;
}

