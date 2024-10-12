#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *addr; 
};
typedef struct node *NODE; 

NODE Insertatbeg(NODE start, int item) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = start;
    return temp;
}

NODE InsertatEnd(NODE start, int item) {
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = NULL;

    if (start == NULL) {
        return temp;
    }

    cur = start;
    while (cur->addr != NULL) {
        cur = cur->addr;
    }
    cur->addr = temp;
    return start;
}

NODE deleteatbeg(NODE start, int *item) {
    NODE temp;
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    temp = start;
    start = start->addr;
    *item = temp->data;
    printf("Deleted element is: %d\n", *item);
    free(temp);
    return start;
}

NODE deleteatEnd(NODE start, int *item) {
    NODE prev, cur;
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (start->addr == NULL) { // Only one node in the list
        *item = start->data;
        printf("Node deleted is: %d\n", *item);
        free(start);
        return NULL;
    }

    cur = start;
    prev = NULL;
    while (cur->addr != NULL) {
        prev = cur;
        cur = cur->addr;
    }

    prev->addr = NULL;
    *item = cur->data;
    printf("Node deleted is: %d\n", *item);
    free(cur);
    return start;
}

void display(NODE start) {
    NODE cur = start;
    if (cur == NULL) {
        printf("List is empty\n");
        return;
    }
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->addr;
    }
    printf("NULL\n");
}

int main() {
    NODE start = NULL;
    int choice, item;

    while (1) {
        printf("\n\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at beginning: ");
                scanf("%d", &item);
                start = Insertatbeg(start, item);
                break;
    
            case 2:
                printf("Enter the element to insert at end: ");
                scanf("%d", &item);
                start = InsertatEnd(start, item);
                break;
    
            case 3:
                start = deleteatbeg(start, &item);
                break;
    
            case 4:
                start = deleteatEnd(start, &item);
                break;
    
            case 5:
                printf("The linked list is: \n");
                display(start);
                break;
    
            case 6:
                printf("Exiting...\n");
                exit(0); // Exit the program
    
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}