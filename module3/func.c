#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* addr;
};
typedef struct node* NODE;

NODE Invert(NODE lead) {
    NODE middle, trail;
    middle = NULL;

    while (lead) {
        trail = middle;       // Save the previous middle
        middle = lead;        // Move middle to current lead
        lead = lead->addr;    // Move lead one step forward
        middle->addr = trail; // Point middle's addr to previous node
    }

    return middle; // Middle will be the new head
}

// Function to concatenate two singly linked lists
NODE concatenate(NODE ptr1, NODE ptr2) {
    NODE temp;

    // If first list is empty, return second list
    if (!ptr1)
        return ptr2;

    // If second list is empty, return first list
    if (!ptr2)
        return ptr1;

    // Store the head of first list
    temp = ptr1;

    // Traverse to the end of first list
    while (temp->addr != NULL) {
        temp = temp->addr;
    }

    // Connect the last node of first list to head of second list
    temp->addr = ptr2;
    return ptr1;
}