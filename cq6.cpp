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

char encryptChar(char p, int a, int b) {
    if (!isalpha(p)) return p; 

    int pVal = toupper(p) - 'A';

    int cVal = (a * pVal + b) % 26;

    return cVal + 'A';
}

char decryptChar(char c, int a, int b) {
    if (!isalpha(c)) return c; 
    int a_inv = 0;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    int cVal = toupper(c) - 'A';

    int pVal = (a_inv * (cVal - b + 26)) % 26;

    return pVal + 'A';
}

int main() {
    int a, b;
    char plaintext[100], ciphertext[100];

    printf("Enter values for a and b (a must be coprime with 26): ");
    scanf("%d %d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Error: a must be coprime with 26.\n");
        return 1;
    }

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encryptChar(plaintext[i], a, b);
    }
    
    printf("Encrypted ciphertext: %s\n", ciphertext);

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = decryptChar(ciphertext[i], a, b);
    }

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

