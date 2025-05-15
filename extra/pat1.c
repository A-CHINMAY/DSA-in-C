#include <stdio.h>

void printHollowParallelogram(int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;    
    int columns = 7; 
    printHollowParallelogram(rows, columns); 
    return 0;
}
