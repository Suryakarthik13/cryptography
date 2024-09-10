#include <stdio.h>
#include <ctype.h>

void caesarCipher(char *text, int k) {
    char ch;
    for(int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + k) % 26 + offset;
        }
        
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int k;

    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value (1-25): ");
    scanf("%d", &k);

    if(k < 1 || k > 25) {
        printf("Invalid shift value! Please enter a number between 1 and 25.\n");
        return 1;
    }

    caesarCipher(text, k);

    printf("Encrypted text: %s\n", text);

    return 0;
}
