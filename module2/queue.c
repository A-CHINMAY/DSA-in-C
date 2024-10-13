#include <stdio.h>
#define MAX 5
int q[MAX];     
int front = -1; 
int rear = -1;  

void enqueue(int item) {

    if (rear == MAX - 1) {
        printf("Queue Overflow n");
    } else {
        if (front == -1) {             
            front = front+1; 
        }
        rear = rear + 1;
        q[rear] = item;
    }
}

void dequeue() {

    if (front == -1) {
        printf("Queue underflow n");
    } else {
        int delitem = q[front];
        printf("deleted element is:%d ", delitem);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }
    
}

void display() {

    if (front == -1) {
        printf("Queue is empty");
    } else {
        printf("The elements of queue are :\n");
        for (int i = front; i <= rear; i++) {
            printf("% d\t", q[i]);
        }
    }
    
}

int main() {
    int choice, item;

    while (1)
    {
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
                return 0;
            default:
                printf("Invalid choice!choose a valid option.\n");
        }
    }
}