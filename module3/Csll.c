#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;

NODE Insertatbeg(NODE start, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if (start == NULL)
    {
        temp->addr = temp; // First node points to itself
        return temp;
    }

    cur = start;
    while (cur->addr != start)
    { // Traverse to the last node
        cur = cur->addr;
    }

    temp->addr = start;
    cur->addr = temp; // Update the last node's `addr` to point to new node
    return temp;      // New node becomes the head
}

NODE InsertatEnd(NODE start, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if (start == NULL)
    {
        temp->addr = temp; // First node points to itself
        return temp;
    }

    cur = start;
    while (cur->addr != start)
    { // Traverse to the last node
        cur = cur->addr;
    }

    cur->addr = temp;
    temp->addr = start; // Last node points back to the head
    return start;       // Head remains unchanged
}

NODE deleteatbeg(NODE start, int *item)
{
    NODE temp, cur;

    if (start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    *item = start->data;

    if (start->addr == start)
    { // Only one node in the list
        printf("Deleted element is: %d\n", *item);
        free(start);
        return NULL;
    }

    cur = start;
    while (cur->addr != start)
    { // Traverse to the last node
        cur = cur->addr;
    }

    temp = start;
    cur->addr = start->addr; // Update the last node's `addr` to skip the first node
    start = start->addr;     // Move the head pointer
    printf("Deleted element is: %d\n", *item);
    free(temp);
    return start;
}

NODE deleteatEnd(NODE start, int *item)
{
    NODE prev, cur;

    if (start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (start->addr == start)
    { // Only one node in the list
        *item = start->data;
        printf("Deleted element is: %d\n", *item);
        free(start);
        return NULL;
    }

    cur = start;
    prev = NULL;
    while (cur->addr != start)
    { // Traverse to the last node
        prev = cur;
        cur = cur->addr;
    }

    prev->addr = start; // Update the second-to-last node to point to the head
    *item = cur->data;
    printf("Deleted element is: %d\n", *item);
    free(cur);
    return start;
}

void display(NODE start)
{
    NODE cur;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    cur = start;
    printf("The circular linked list is: \n");
    do
    {
        printf("%d -> ", cur->data);
        cur = cur->addr;
    } while (cur != start);
    printf("HEAD\n");
}

int getLength(NODE start)
{
    if (start == NULL)
    {
        return 0; // List is empty
    }

    int count = 0;
    NODE cur = start;
    do
    {
        count++;
        cur = cur->addr;
    } while (cur != start); // Traverse until we reach the head again

    return count;
}

int main()
{
    NODE start = NULL;
    int choice, item;

    while (1)
    {
        printf("\n\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Get Length of List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("The circular linked list is: \n");
            display(start);
            break;

        case 6:
            printf("Length of the circular linked list is: %d\n", getLength(start));
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
