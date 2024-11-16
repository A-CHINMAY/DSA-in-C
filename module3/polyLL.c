#include <stdio.h>
#include <stdlib.h>
typedef struct polynode {
    int coef;
    int exp;
    struct polynode *addr;
} polynode;

typedef struct polynode *polypointer;

// Function to create and return a new node
polypointer getnode() {
    polypointer temp = (polypointer)malloc(sizeof(struct polynode));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return temp;
}

// Function to compare two terms
int compare(int a, int b) {
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

// Function to attach a new node
void attach(int coef, int exp, polypointer *ptr) {
    polypointer temp = getnode();
    temp->coef = coef;
    temp->exp = exp;
    temp->addr = NULL;
    (*ptr)->addr = temp;
    *ptr = temp;
}

// Function to add two polynomials
polypointer polyadd(polypointer a, polypointer b) {
    polypointer c, rear, temp;
    int sum;

    // Get a new node for the header of result polynomial
    rear = getnode();
    c = rear;

    while (a && b) {
        switch (compare(a->exp, b->exp)) {
        case -1: // a's exponent is smaller
            attach(b->coef, b->exp, &rear);
            b = b->addr;
            break;

        case 0: // exponents are equal
            sum = a->coef + b->coef;
            if (sum != 0) {
                attach(sum, a->exp, &rear);
            }
            a = a->addr;
            b = b->addr;
            break;

        case 1: // a's exponent is larger
            attach(a->coef, a->exp, &rear);
            a = a->addr;
            break;
        }
    }

    // Copy remaining terms from a, if any
    for (; a != NULL; a = a->addr)
        attach(a->coef, a->exp, &rear);

    // Copy remaining terms from b, if any
    for (; b != NULL; b = b->addr)
        attach(b->coef, b->exp, &rear);

    temp = c;
    c = c->addr;
    free(temp); // Free the header node

    return c;
}

// Function to create a polynomial
polypointer create() {
    polypointer head, rear;
    int coef, exp;
    char choice;
    head = getnode();
    rear = head;

    do {
        printf("Enter coefficient: ");
        scanf("%d", &coef);
        printf("Enter exponent: ");
        scanf("%d", &exp);

        attach(coef, exp, &rear);

        printf("Do you want to add more terms? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    polypointer temp = head;
    head = head->addr;
    free(temp);

    return head;
}

// Function to display a polynomial
void display(polypointer poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->exp);
        poly = poly->addr;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    printf("Enter first polynomial:\n");
    polypointer poly1 = create();
    printf("Enter second polynomial:\n");
    polypointer poly2 = create();
    printf("\nFirst polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);
    printf("Sum of polynomials: ");
    polypointer result = polyadd(poly1, poly2);
    display(result);
}