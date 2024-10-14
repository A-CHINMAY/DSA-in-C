#include <stdio.h>
typedef struct {
    int coef;  // Coefficient
    int power; // Power of x
} term;

term poly[200]; // Array to store both input polynomials and the result
int avail = 0;  // Keeps track of the next available index

// Function to compare powers of two terms
int compare(int powerA, int powerB) {
    if (powerA > powerB)
        return 1;
    else if (powerA < powerB)
        return -1;
    else
        return 0;
}
// Function to attach a term (coefficient and power) to the polynomial result
void attach(int coef, int power){
    poly[avail].coef = coef;
    poly[avail].power = power;
    avail++; // Move to the next available index
}
// Function to add two polynomials
void polyAdd(int startA, int finishA, int startB, int finishB) {
    int coeff;

    // Adding polynomials term by term
    while (startA <= finishA && startB <= finishB) {
        switch (compare(poly[startA].power, poly[startB].power)) {
        case -1: // If power of term in B is greater, add it to result
            attach(poly[startB].coef, poly[startB].power);
            startB++;
            break;
        case 0: // If powers are equal, add coefficients
            coeff = poly[startA].coef + poly[startB].coef;
            if (coeff != 0) {
                attach(coeff, poly[startA].power);
            }
            startA++;
            startB++;
            break;
        case 1: // If power of term in A is greater, add it to result
            attach(poly[startA].coef, poly[startA].power);
            startA++;
            break;
        }
    }

    // Add remaining terms from polynomial A
    while (startA <= finishA) {
        attach(poly[startA].coef, poly[startA].power);
        startA++;
    }

    // Add remaining terms from polynomial B
    while (startB <= finishB) {
        attach(poly[startB].coef, poly[startB].power);
        startB++;
    }
}

// Function to display a polynomial
void displayPoly(int start, int finish) {
    for (int i = start; i <= finish; i++) {
        printf("%dx^%d", poly[i].coef, poly[i].power);
        if (i < finish) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of the first polynomial (coefficient and power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &poly[i].coef, &poly[i].power);
    }
    int startA = 0, finishA = n - 1; // Marking start and end of the first polynomial

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);
    printf("Enter the terms of the second polynomial (coefficient and power):\n");
    for (int i = n; i < n + m; i++) {
        scanf("%d %d", &poly[i].coef, &poly[i].power);
    }
    int startB = n, finishB = n + m - 1; // Marking start and end of the second polynomial

    avail = finishB + 1; // Next available index after both input polynomials

    // Adding the two polynomials
    polyAdd(startA, finishA, startB, finishB);

    // Displaying the result
    printf("Resultant polynomial after addition:\n");
    displayPoly(finishB + 1, avail - 1);

    return 0;
}
