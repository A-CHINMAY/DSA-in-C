#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count = 0;

struct node {
    int data;
    struct node *addr;
};
typedef struct node *NODE;

NODE push(NODE start, int item) {
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

NODE pop(NODE start) {
    NODE temp;
    if (start == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    temp = start;
    start = start->addr;
    printf("Node deleted is: %d\n", temp->data);
    count = count - 1;
    free(temp);
    return start;
}

void display(NODE start) {
    if (start == NULL) {
        printf("Stack is empty\n");
        return;
    }
    NODE temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}

int main() {
    NODE start = NULL;
    int ch, item;
    for (;;) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            start = push(start, item);
            break;
        case 2:
            start = pop(start);
            break;
        case 3:
            display(start);
            break;
        default:
            exit(0);
        }
    }
}