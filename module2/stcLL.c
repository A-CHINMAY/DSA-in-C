#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count = 0;

struct node {
    int data;
    struct node *addr;
};
typedef struct node *NODE;

NODE Push(NODE start, int item) {
    NODE temp;
    if (count >= SIZE) {
        printf("Stack overflow\n");
        return start;
    }
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = start;
    count = count + 1;
    return temp;
}

NODE Pop(NODE start) {
    NODE temp;
    if (start == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    temp = start;
    start = start->addr;
    printf("Node deleted is %d\n", temp->data);
    free(temp);
    count = count - 1;
    return start;
}

void Display(NODE start) {
    NODE temp;
    if (start == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}


int main() {
    NODE start = NULL;
    int choice, item;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                start = Push(start, item);
                break;
            case 2:
                start = Pop(start);
                break;
            case 3:
                Display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}