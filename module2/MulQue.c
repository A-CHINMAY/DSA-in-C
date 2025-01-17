#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int Q[SIZE];
int boundary[10];
int front[10];
int rear[10];
int n, i, item, ch;

void enqueue() {
    printf("Enter queue number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid queue number\n");
        return;
    }
    if (rear[i] == boundary[i + 1]) {
        printf("Queue %d is full\n", i);
        return;
    }
    printf("Enter item: ");
    scanf("%d", &item);
    if (front[i] == -1)
        front[i] = boundary[i] + 1;
    rear[i] = rear[i] + 1;
    Q[rear[i]] = item;
}

void dequeue() {
    printf("Enter queue number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid queue number\n");
        return;
    }
    if (front[i] == -1 || front[i] > rear[i]) {
        printf("Queue %d is empty\n", i);
        return;
    }
    printf("Item deleted: %d\n", Q[front[i]]);
    front[i] = front[i] + 1;
    if (front[i] > rear[i]) {
        front[i] = rear[i] = -1; // Reset queue when empty
    }
}

void display() {
    printf("Enter queue number (0-%d): ", n - 1);
    scanf("%d", &i);
    if (i >= n) {
        printf("Invalid queue number\n");
        return;
    }
    if (front[i] == -1 || front[i] > rear[i]) {
        printf("Queue %d is empty\n", i);
        return;
    }
    for (int j = front[i]; j <= rear[i]; j++)
        printf("%d ", Q[j]);
    printf("\n");
}

int main() {
    printf("Enter number of queues (1-10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        boundary[i] = SIZE / n * (i + 1) - 1;
        front[i] = rear[i] = -1; // Initialize front and rear for each queue
    }
    boundary[n] = SIZE - 1; // last boundary
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
