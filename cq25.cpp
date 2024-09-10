#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    unsigned long long n = 91; 
    unsigned long long e = 5; 

    unsigned long long M = 7; 

    unsigned long long common_factor = gcd(M, n);

    if (common_factor != 1) {
        printf("Common factor found: %llu\n", common_factor);
        unsigned long long other_factor = n / common_factor;
        printf("Other factor: %llu\n", other_factor);
        printf("We have factored n as %llu = %llu * %llu\n", n, common_factor, other_factor);
    } else {
        printf("No common factor found. RSA is still secure.\n");
    }

    return 0;
}

