#include <stdio.h>
#define MAX 100
typedef struct{
    int row;
    int col;
    int value;
} term;
void fast_transpose(term a[], term b[]) {
    int row_terms[MAX], start_pos[MAX];
    int i, j;

    // Step 1: Initialize
    int num_cols = a[0].col;    // Number of columns in matrix 'a'
    int num_terms = a[0].value; // Number of non-zero elements in matrix 'a'

    b[0].row = num_cols; // Transposed matrix will have 'num_cols' rows
    b[0].col = a[0].row; // and 'a[0].row' columns
    b[0].value = num_terms;

    // Step 2: Initialize row_terms array to 0
    for (i = 0; i < num_cols; i++)
        row_terms[i] = 0;

    // Step 3: Count occurrences of each column in 'a[]'
    for (i = 1; i <= num_terms; i++)
        row_terms[a[i].col]++;

    // Step 4: Calculate starting positions in transposed matrix 'b[]'
    start_pos[0] = 1;
    for (i = 1; i < num_cols; i++)
        start_pos[i] = start_pos[i - 1] + row_terms[i - 1];

    // Step 5: Place elements in transposed matrix 'b[]'
    for (i = 1; i <= num_terms; i++)  {
        j = start_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}
// Function to print sparse matrix
void print_sparse_matrix(term a[]) {
    int num_terms = a[0].value;
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i <= num_terms; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main() {
    term a[] = {
        {3, 3, 3}, // 3x3 matrix with 3 non-zero elements
        {0, 1, 1}, // Non-zero element at (0, 1) with value 1
        {1, 0, 2}, // Non-zero element at (1, 0) with value 2
        {2, 2, 3}  // Non-zero element at (2, 2) with value 3
    };

    term b[MAX]; // For storing the transpose

    printf("\nOriginal Sparse Matrix:\n");
    print_sparse_matrix(a);

    // Transpose the sparse matrix using fast transpose
    fast_transpose(a, b);

    printf("\nTransposed Sparse Matrix:\n");
    print_sparse_matrix(b);
}