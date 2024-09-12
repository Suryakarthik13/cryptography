#include <stdio.h>

// Define the 2x2 key matrix (you can choose your own values)
int key[2][2] = {{3, 2}, {1, 4}};

// Encrypt a pair of letters using the Hill cipher
void encrypt(char p1, char p2) {
    int c1, c2;
    c1 = (key[0][0] * (p1 - 'A') + key[0][1] * (p2 - 'A')) % 26;
    c2 = (key[1][0] * (p1 - 'A') + key[1][1] * (p2 - 'A')) % 26;
    printf("Encrypted Cipher Text: %c %c\n", c1 + 'A', c2 + 'A');
}

int main() {
    char plain1, plain2;
    printf("Enter two uppercase letters (e.g., SAN): ");
    scanf("%c %c", &plain1, &plain2);

    // Assume the key matrix is known (for demonstration purposes)
    // In practice, the key should be kept secret.
    encrypt(plain1, plain2);

    return 0;
}

