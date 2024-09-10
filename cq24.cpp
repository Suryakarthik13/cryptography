#include <stdio.h>

int main() {
    int n = 3599, e = 31;
    int p = 47, q = 77;  
    int phi = (p - 1) * (q - 1);

    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;
        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }

    int d = (r > 1) ? -1 : (t < 0 ? t + phi : t);

    if (d == -1)
        printf("No modular inverse found.\n");
    else
        printf("Private Key (d) = %d\n", d);

    return 0;
}


