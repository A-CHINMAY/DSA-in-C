#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;
// Function to create a new node
NODE createNode(int item) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning
NODE insertAtBeginning(NODE start, int item) {
    NODE newNode = createNode(item);
    if (start == NULL) {
        return newNode;
    }
    newNode->next = start;
    start->prev = newNode;
    return newNode;
}

// Insert a node at the end
NODE insertAtEnd(NODE start, int item) {
    NODE newNode = createNode(item);
    if (start == NULL) {
        return newNode;
    }
    NODE temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return start;
}

// Delete a node from the beginning
NODE deleteFromBeginning(NODE start) {
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    printf("Deleted node: %d\n", temp->data);
    free(temp);
    return start;
}

// Delete a node from the end
NODE deleteFromEnd(NODE start) {
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = start;
    if (temp->next == NULL) {
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        return NULL;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
    return start;
}

// Display the list in forward order
void display(NODE start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = start;
    printf("List in forward order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE start = NULL;
    int choice, item;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the item to insert at beginning: ");
            scanf("%d", &item);
            start = insertAtBeginning(start, item);
            break;
        case 2:
            printf("Enter the item to insert at end: ");
            scanf("%d", &item);
            start = insertAtEnd(start, item);
            break;
        case 3:
            start = deleteFromBeginning(start);
            break;
        case 4:
            start = deleteFromEnd(start);
            break;
        case 5:
            display(start);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}