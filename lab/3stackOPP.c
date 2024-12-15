#include <stdio.h>
#define MAX 5
int top = -1;
int stack[MAX];

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    }
    else {
        printf("Element to be popped is %d\n", stack[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("The stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int isPalindrome() {
    if (top == -1) {
        printf("Stack is empty, cannot check for palindrome\n");
        return 0;
    }

    int i = 0, j = top;
    while (i < j) {
        if (stack[i] != stack[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Is a palindrome
}

void main() {
    int choice, item;
    for (;;) {
        printf("\n1: Push 2: Pop 3: Display 4: Check Palindrome 5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
    
            case 2:
                pop();
                break;
    
            case 3:
                display();
                break;
    
            case 4:
                if (isPalindrome())
                {
                    printf("The stack is a palindrome\n");
                }
                else
                {
                    printf("The stack is not a palindrome\n");
                }
                break;
    
            case 5:
                exit(0);
    
            default:
                printf("Wrong choice\n");
        }
    }
}
