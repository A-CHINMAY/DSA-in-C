#include <stdio.h>
#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} term;
term a[MAX];

int main() {
    int i, j, k;

    // Input for sparse matrix dimensions and number of non-zero elements
    printf("Enter number of rows, columns and number of non-zero elements: ");
    scanf("%d%d%d", &a[0].row, &a[0].col, &a[0].value);

    printf("Enter the row, column, and value for each non-zero element:\n");
    for (i = 1; i <= a[0].value; i++) {
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].value);
    }
    // Output of the sparse matrix
    printf("Output of the matrix:\n");
    k = 1; // k points to the current non-zero element
    for (i = 0; i < a[0].row; i++) {
        for (j = 0; j < a[0].col; j++) {
            if (i == a[k].row && j == a[k].col) {
                printf("%d\t", a[k].value); // Print non-zero element
                k++;
            }
            else {
                printf("0\t"); // Print zero where no element is present
            }
        }
        printf("\n");
    }

    return 0;
}
