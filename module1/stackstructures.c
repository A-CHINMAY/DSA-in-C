#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct STACK{
    int data[SIZE];
    int top;
};

void push(struct STACK *S, int item) {
    if (S->top == SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        S->top++;
        S->data[S->top] = item;
    }
}

void pop(struct STACK *S) {
    if (S->top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("element to be popped is %d", S->data[S->top]);
        S->top--;
    } 
}

void display(struct STACK *S){
    if (S->top == -1){
        printf("Stack is empty\n");
    }else {
        printf("Elements in the stack:\n");
        for (int i = S->top; i >= 0; i--) {
            printf("%d ", S->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct STACK S;
    S.top = -1; // Initialize the stack as empty
    int choice, item;
    for(;;){
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &item);
            push(&S, item);
            break;

        case 2:
            pop(&S);
            break;

        case 3:
            display(&S);
            break;

        case 4:
            exit(0);

        default:
            printf(" wrong choice ");
        }
    }
    
}