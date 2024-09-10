#include <stdio.h>
#include <ctype.h> 

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}

char decryptChar(char c, int a, int b) {
    if (!isalpha(c)) return c;

    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("Error: 'a' has no modular inverse under mod 26.\n");
        return c;
    }

    int cVal = toupper(c) - 'A';

    int pVal = (a_inv * (cVal - b + 26)) % 26;

    return pVal + 'A';
}

int main() {
    int a, b;
    char ciphertext[100], plaintext[100];

    for (a = 1; a < 26; a++) {
        if ((15 * a) % 26 == 19) {
            break;
        }
    }

    if (a == 26) {
        printf("Error: No valid value for 'a' found.\n");
        return 1;
    }

    b = (1 - (a * 4) % 26 + 26) % 26;

    printf("Found values: a = %d, b = %d\n", a, b);

    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = decryptChar(ciphertext[i], a, b);
    }

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

