polypointer polyadd(polypointer a, polypointer b) {
    polypointer c, rear, temp;
    int sum;

    // Create a new header node for the result polynomial
    rear = getnode();  // Allocate memory for the header node
    rear->addr = rear; // Initialize rear as a circular linked list
    c = rear;

    polypointer aStart = a, bStart = b; // Store starting points of a and b

    // Add terms from both polynomials
    do {
        switch (compare(a->exp, b->exp)) {
        case -1: // b's exponent is larger
            attach(b->coef, b->exp, &rear);
            b = b->addr;
            break;

        case 0: // Exponents are equal
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
    } while (a != aStart && b != bStart); // Continue until we've traversed both polynomials completely

    // Add remaining terms from a, if any
    while (a != aStart) {
        attach(a->coef, a->exp, &rear);
        a = a->addr;
    }

    // Add remaining terms from b, if any
    while (b != bStart) {
        attach(b->coef, b->exp, &rear);
        b = b->addr;
    }

    rear->addr = c->addr; // Close the circular linked list
    free(c);              // Free the temporary header node

    return rear->addr; // Return the result polynomial
}