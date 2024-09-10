#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int row = 0, col = 0;
    
    for(int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if(ch == 'J') ch = 'I';
        if(!used[ch - 'A']) {
            matrix[row][col++] = ch;
            used[ch - 'A'] = 1;
            if(col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
    
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        if(ch == 'J') continue; 
        if(!used[ch - 'A']) {
            matrix[row][col++] = ch;
            used[ch - 'A'] = 1;
            if(col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}

void printMatrix(char matrix[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void prepareText(char *text, char *preparedText) {
    int len = strlen(text);
    int j = 0;
    
    for(int i = 0; i < len; i++) {
        char ch = toupper(text[i]);
        if(isalpha(ch)) {
            if(ch == 'J') ch = 'I'; 
            preparedText[j++] = ch;
        }
    }
    preparedText[j] = '\0';
}

void createDigraphs(char *preparedText, char digraphs[][2]) {
    int len = strlen(preparedText);
    int i = 0, j = 0;
    
    while(i < len) {
        char first = preparedText[i++];
        char second = (i < len && preparedText[i] != first) ? preparedText[i++] : 'X';
        digraphs[j][0] = first;
        digraphs[j++][1] = second;
    }
    
    if(strlen(preparedText) % 2 != 0) {
        digraphs[j][0] = preparedText[len-1];
        digraphs[j][1] = 'X';
    }
}

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptDigraphs(char digraphs[][2], char matrix[SIZE][SIZE], int digraphCount, char *cipherText) {
    int idx = 0;
    
    for(int k = 0; k < digraphCount; k++) {
        int row1, col1, row2, col2;
        
        findPosition(matrix, digraphs[k][0], &row1, &col1);
        findPosition(matrix, digraphs[k][1], &row2, &col2);
        
        if(row1 == row2) {
            cipherText[idx++] = matrix[row1][(col1 + 1) % SIZE];
            cipherText[idx++] = matrix[row2][(col2 + 1) % SIZE];
        } else if(col1 == col2) {
            cipherText[idx++] = matrix[(row1 + 1) % SIZE][col1];
            cipherText[idx++] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            cipherText[idx++] = matrix[row1][col2];
            cipherText[idx++] = matrix[row2][col1];
        }
    }
    cipherText[idx] = '\0';
}

int main() {
    char key[100], text[100], preparedText[100];
    char matrix[SIZE][SIZE];
    char cipherText[100];
    char digraphs[50][2];
    int digraphCount = 0;

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    prepareMatrix(key, matrix);
    printf("5x5 Matrix:\n");
    printMatrix(matrix);
    
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    prepareText(text, preparedText);
    
    digraphCount = (strlen(preparedText) + 1) / 2;
    createDigraphs(preparedText, digraphs);
    
    encryptDigraphs(digraphs, matrix, digraphCount, cipherText);
    
    printf("Encrypted text: %s\n", cipherText);
    
    return 0;
}
