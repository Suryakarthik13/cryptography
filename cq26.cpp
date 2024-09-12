#include <stdio.h>

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to simulate key regeneration attempt
void simulateKeyRegeneration(int n, int e, int d_leaked) {
    printf("Initial modulus n: %d\n", n);
    printf("Leaked private key d: %d\n", d_leaked);
    
    int new_e = 5;      // Bob generates a new public key exponent
    int new_d = 65;     // Bob generates a new private key (hypothetically)

    // Show that the new keys won't help because n is still the same and compromised.
    printf("Bob generates new public key e: %d\n", new_e);
    printf("Bob generates new private key d: %d\n", new_d);

    // An attacker could still use the leaked information to compromise n, so this is unsafe.
    printf("Warning: Since the modulus n is the same, Bob's system is still vulnerable!\n");
}

int main() {
    int p = 11;   // Example small prime number
    int q = 7;    // Example small prime number
    int n = p * q;  // Modulus n = p * q
    int e = 3;    // Public key exponent
    int d = 27;   // Private key (assumed)

    // Simulate a leak of the private key
    printf("Private key leaked!\n");
    simulateKeyRegeneration(n, e, d);

    return 0;
}

