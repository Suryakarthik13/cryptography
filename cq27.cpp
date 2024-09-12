#include <stdio.h>

int main() {
    char message[] = "HELLO";  // Sample message
    int i, encrypted[5];
    int e = 17;   // Public key exponent
    int n = 3233; // Example RSA modulus (p*q)

    printf("Original message: %s\n", message);

    for (i = 0; i < 5; i++) {
        // Convert each letter to a number (A=0, Z=25)
        int m = message[i] - 'A';

        // Encrypt each number using RSA: c = m^e mod n
        int c = 1;
        for (int j = 0; j < e; j++) {
            c = (c * m) % n;
        }
        encrypted[i] = c;
    }

    printf("Encrypted message: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    printf("This encryption method is insecure due to frequency analysis attacks.\n");

    return 0;
}

