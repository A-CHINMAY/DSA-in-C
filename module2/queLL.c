#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count = 0;
struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = item;
    temp->next = NULL;
    return temp;
}

NODE Enqueue(NODE rear, int item) {
    if (count >= SIZE) {
        printf("Queue overflow\n");
        return rear;
    }

    NODE temp = createNode(item);
    if (rear == NULL) {
        count++; // Increment count when adding the first element
        return temp;
    }
    rear->next = temp;
    count++; // Increment count after adding the new element
    return temp;
}

NODE Dequeue(NODE *front) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return NULL;
    }

    NODE temp = *front;
    printf("Node dequeued is %d\n", temp->data);
    *front = (*front)->next;
    free(temp);
    count--; // Decrement count after removing an element
    return *front;
}

void Display(NODE front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    NODE temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE front = NULL, rear = NULL;
    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                if (front == NULL) {
                    front = Enqueue(rear, item); // For the first element, front and rear are the same
                    rear = front;
                } else {
                    rear = Enqueue(rear, item);
                }
                break;
            case 2:
                front = Dequeue(&front);
                if (front == NULL) {
                    rear = NULL; // If the queue becomes empty, reset rear as well
                }
                break;
            case 3:
                Display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
