#include <stdio.h>
#include <stdlib.h>

int *x, q = 0, n;

int can_place(int p) {
    for (int i = 0; i < q; i++) {
        if (x[i] == p || (x[i] - i) == (p - q) || (x[i] + i) == (p + q))
            return 0;
    }
    return 1;
}

void print_board() {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

void n_queens() {
    for (int p = 0; p < n; p++) {
        if (can_place(p)) {
            x[q] = p;
            q++;
            if (q == n) {
                print_board();
            }
            else {
                n_queens();
            }
            q--; 
        }
    }
}

int main() {
    printf("Enter the board size (n): ");
    scanf("%d", &n);

    x = (int *)calloc(n, sizeof(int));

    n_queens();

    free(x);
    return 0;
}
