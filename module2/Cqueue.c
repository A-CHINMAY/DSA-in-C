#include <stdio.h>
#define MAX 5 
int q[MAX];     
int front = -1; 
int rear = -1;  

void enqueue(int item) {

    if( front == (rear + 1) % MAX ) { 
        printf("Queue Overflow\n");
    }
    else {
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % MAX; 
        q[rear] = item;
        printf("Inserted element is: %d\n", item);
    }
}

void dequeue() {
    if (front == -1) { 
        printf("Queue underflow\n");
    } else {
        int delitem = q[front];
        printf("Deleted element is: %d\n", delitem);

        if (front == rear) { 
            front = -1;
            rear = -1; 
        } else {
            front = (front + 1) % MAX; 
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("The elements of the queue are:\n");
        for (int i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d\t", q[i]);
        }
        printf("%d\t", q[rear]); 
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n\nCircular Queue Operations Menu:");
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
                return 0;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
}
