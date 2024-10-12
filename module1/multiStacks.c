#include <stdio.h>
#define SIZE 100
int s[SIZE], top[10], boundary[10]; // Stack array and top/boundary arrays for multi-stack
int n, i, j, item;
// Push operation
void push(int i) {
    if (top[i] == boundary[i + 1]) {
        printf("Stack %d is full\n", i + 1);
    }
    else {
        printf("Enter item to push into stack %d: ", i + 1);
        scanf("%d", &item);
        top[i] = top[i] + 1;
        s[top[i]] = item;
    }
}

// Pop operation
void pop(int i) {
    if (top[i] == boundary[i]) {
        printf("Stack %d is empty\n", i + 1);
    }
    else {
        printf("Item deleted from stack %d: %d\n", i + 1, s[top[i]]);
        top[i] = top[i] - 1;
    }
}

// Display operation
void display(int i) {
    if (top[i] == boundary[i]) {
        printf("Stack %d is empty\n", i + 1);
    }
    else {
        printf("Elements in stack %d are: ", i + 1);
        for (j = top[i]; j > boundary[i]; j--) {
            printf("%d ", s[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int Snum,choice;
    printf("Enter the number of stacks: ");
    scanf("%d", &n);

    // Initialize boundaries and tops of each stack
    for (i = 0; i < n; i++) {
        top[i] = (SIZE / n) * i - 1;
        boundary[i] = top[i];
    }
    boundary[n] = SIZE - 1;

    // Menu-driven program for stack operations
    printf("Enter stack number (1 to %d): ", n);
    scanf("%d", &Snum);
    i = Snum - 1;

    printf("1: Push\n2: Pop\n3: Display\n4: Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            push(i);
            break;
        case 2:
            pop(i);
            break;
        case 3:
            display(i);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
    }
}
