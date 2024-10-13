#include <stdio.h>
#include <stdlib.h>
int *q;           
int front = -1; 
int rear = -1;    
int capacity = 5; 

void enqueue(int item) {
    
    if ((rear + 1) % capacity == front) {
        printf("Queue Overflow. Resizing queue...\n");
        capacity *= 2;
        q = (int *)realloc(q, capacity * sizeof(int));

        if (front > rear) {
            for (int i = 0; i <= rear; i++) {
                q[i + capacity / 2] = q[i];
            }
            rear = rear + capacity / 2; 
        }
    }

    if (front == -1){
        front = 0;
    }
    rear = (rear + 1) % capacity;
    q[rear] = item;
    printf("Inserted element: %d\n", item);
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
        } else {
            front = (front + 1) % capacity; // Circular increment of front
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The elements of the queue are:\n");
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            printf("%d\t", q[i]);
        }
        printf("%d\t", q[rear]); 
        printf("\n");
    }
}

int main() {
    q = (int *)malloc(capacity * sizeof(int));
    int choice, item;

    while (1) {
        printf("\nDynamic Circular Queue Operations Menu:");
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
                printf("Invalid choice! Please try again.\n");
        }
    }
}
