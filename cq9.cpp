#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define MAX_MESSAGE_LENGTH 100

// Playfair cipher grid
char grid[SIZE][SIZE];

// Function to remove duplicates and construct grid
void generateGrid(const char *key) {
    int used[26] = {0}; // To mark letters as used
    used['J' - 'A'] = 1; // Treat I and J as the same letter

    int row = 0, col = 0;
    for (int i = 0; i < strlen(key); i++) {
        char c = toupper(key[i]);
        if (!used[c - 'A']) {
            grid[row][col++] = c;
            used[c - 'A'] = 1;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }

    // Fill remaining letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            grid[row][col++] = c;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}

// Function to find position of a character in the grid
void findPosition(char c, int *row, int *col) {
    if (c == 'J') c = 'I'; // Treat I and J the same
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decode a digraph
void decodeDigraph(char *digraph) {
    int row1, col1, row2, col2;
    findPosition(digraph[0], &row1, &col1);
    findPosition(digraph[1], &row2, &col2);

    // Same row
    if (row1 == row2) {
        digraph[0] = grid[row1][(col1 - 1 + SIZE) % SIZE];
        digraph[1] = grid[row2][(col2 - 1 + SIZE) % SIZE];
    }
    // Same column
    else if (col1 == col2) {
        digraph[0] = grid[(row1 - 1 + SIZE) % SIZE][col1];
        digraph[1] = grid[(row2 - 1 + SIZE) % SIZE][col2];
    }
    // Rectangle swap
    else {
        digraph[0] = grid[row1][col2];
        digraph[1] = grid[row2][col1];
    }
}

// Function to decode the entire message
void decodeMessage(const char *message, char *decodedMessage) {
    char digraph[3] = {0}; // For storing pairs of letters
    int len = strlen(message);
    int decodedIndex = 0;

    for (int i = 0; i < len; i += 2) {
        digraph[0] = toupper(message[i]);
        digraph[1] = toupper(message[i + 1]);
        decodeDigraph(digraph);
        decodedMessage[decodedIndex++] = digraph[0];
        decodedMessage[decodedIndex++] = digraph[1];
    }
    decodedMessage[decodedIndex] = '\0'; // Null-terminate the decoded string
}

int main() {
    // The message to decode (Playfair cipher text)
    const char *cipherText = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    // Keyword for generating the Playfair cipher grid (assuming "JFK")
    const char *key = "JFK";

    // Generate the Playfair cipher grid
    generateGrid(key);

    // Buffer to store decoded message
    char decodedMessage[MAX_MESSAGE_LENGTH];

    // Decode the cipher text
    decodeMessage(cipherText, decodedMessage);

    // Print the decoded message
    printf("Decoded Message: %s\n", decodedMessage);

    return 0;
}

