#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 4

int main() {
    // Initialize with specific values
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    printf("2D Array (6 rows × 4 columns):\n");
    printf("==============================\n");

    // Traverse and print using nested loops
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d] = %d\t", i, j, matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
