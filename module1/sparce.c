#include <stdio.h>
// Define the structure 'term' to represent each element in sparse matrix
typedef struct {
    int row;   // Row number
    int col;   // Column number
    int value; // Value of the non-zero element
} term;
// Function to transpose the sparse matrix
void transpose(term a[], term b[]) {
    int n, i, j, currentb;
    n = a[0].value; // Number of non-zero elements

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n > 0) {
        currentb = 1;
        for (i = 0; i < a[0].col; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}
// Function to display a sparse matrix in triplet form
void display(term t[]) {
    int n = t[0].value; // Number of non-zero elements
    printf("Row  Col  Value\n");
    for (int i = 0; i <= n; i++) {
        printf("%d    %d    %d\n", t[i].row, t[i].col, t[i].value);
    }
}

int main() {
    // Example: 3x3 sparse matrix
    // Representation in triplet form: (row, col, value)
    term a[] = {
        {3, 3, 4}, // Metadata: 3 rows, 3 cols, 4 non-zero elements
        {0, 0, 5}, // Non-zero element at (0, 0) with value 5
        {0, 2, 8}, // Non-zero element at (0, 2) with value 8
        {1, 1, 3}, // Non-zero element at (1, 1) with value 3
        {2, 0, 6}  // Non-zero element at (2, 0) with value 6
    };

    // Array to store the transpose of matrix 'a'
    term b[5]; // 5 terms: 1 for metadata and 4 for the elements

    // Transpose the matrix
    transpose(a, b);

    // Display original matrix
    printf("Original matrix:\n");
    display(a);

    // Display transposed matrix
    printf("\nTransposed matrix:\n");
    display(b);
}