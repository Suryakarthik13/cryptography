#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "HELLOWORLD12345";  // 16-byte message
    int blockSize = 8;  // Block size in bytes (64 bits)
    int len = strlen(plaintext);
    int paddingSize = blockSize - (len % blockSize);
    char paddedText[len + paddingSize + 1];  // For the padded message

    strcpy(paddedText, plaintext);

    for (int i = len; i < len + paddingSize - 1; i++) 
        paddedText[i] = '0';  // Zero padding

    paddedText[len + paddingSize - 1] = '1';  // Final bit as '1'
    paddedText[len + paddingSize] = '\0';  // Null-terminate the string

    printf("Padded Message: %s\n", paddedText);

    return 0;
}
