#include <stdio.h>
#include <stdlib.h>

int *q = NULL; 
int front = -1;
int rear = -1;
int capacity = 0; 
void enqueue(int item) {

    if (rear == capacity - 1) { 
        if (capacity == 0) {
            capacity = 1; 
        }
        else {
            capacity *= 2; // Double the capacity
        }

        q = realloc(q, capacity * sizeof(int));
        if (q == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    if (front == -1) { 
        front = 0;
    }
    rear = rear + 1;
    q[rear] = item;
    printf("Enqueued %d\n", item);
}

void dequeue() {

    if (front == -1) {
        printf("Queue underflow\n");
    }
    else {
        int delitem = q[front];
        printf("Deleted element is: %d\n", delitem);
        if (front == rear) { 
            front = -1;
            rear = -1;
        }
        else {
            front = front + 1;
        }
    }
}

void display() {

    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("The elements of the queue are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n\nQueue Operations Menu:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            free(q);
            return 0;
        default:
            printf("Invalid choice! Choose a valid option.\n");
        }
    }
}
