#include <stdio.h>

int main() {
    int matrix[5][5] = {0}; // Initialize all lanes to zero

    printf("Initial state:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Simulate updating the lanes
    matrix[0][0] = 1;  // Example non-zero bit added
    matrix[1][1] = 1;
    matrix[2][2] = 1;

    printf("Updated state:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("In a real SHA-3 process, more complex updates would occur.\n");

    return 0;
}

