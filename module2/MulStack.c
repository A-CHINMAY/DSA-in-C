#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int S[SIZE];
int boundary[10];
int top[10];
int n, i, item, ch;

void push() {
    printf("Enter stack number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid stack number\n");
        return;
    }
    if (top[i] == boundary[i + 1]) {
        printf("Stack %d is full\n", i);
        return;
    }
    printf("Enter item: ");
    scanf("%d", &item);
    top[i] = top[i] + 1;
    S[top[i]] = item;
}

void pop() {
    printf("Enter stack number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid stack number\n");
        return;
    }
    if (top[i] == boundary[i]) {
        printf("Stack %d is empty\n", i);
        return;
    }
    printf("Item deleted: %d\n", S[top[i]]);
    top[i] = top[i] - 1;
}

void display() {
    printf("Enter stack number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid stack number\n");
        return;
    }
    if (top[i] == boundary[i]) {
        printf("Stack %d is empty\n", i);
        return;
    }
    for (int j = boundary[i] + 1; j <= top[i]; j++)
        printf("%d ", S[j]);
    printf("\n");
}

int main() {
    printf("Enter number of stacks (1-10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        boundary[i] = SIZE / n * (i + 1) - 1;
        top[i] = boundary[i];
    }
    boundary[n] = SIZE - 1; // last boundary
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
