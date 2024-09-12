#include <stdio.h>

int main() {
    int a = 5; // Public number a
    int q = 23; // Public prime modulus
    int xA = 6; // Alice's secret
    int xB = 15; // Bob's secret

    // Incorrect exchange: Alice and Bob send xa instead of a^x mod q
    int alice_sends = xA * a;
    int bob_sends = xB * a;

    printf("Alice sends: %d\n", alice_sends);
    printf("Bob sends: %d\n", bob_sends);

    printf("This exchange is insecure because it reveals too much about the secret numbers.\n");

    return 0;
}

