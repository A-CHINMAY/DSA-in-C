#include <stdio.h>
#include <stdlib.h>

struct node {
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *addr;
};
typedef struct node *NODE;

NODE start = NULL;
int count = 0;

NODE create() {
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));

    if (snode == NULL) {
        printf("\nMemory is not available");
        exit(1);
    }
    printf("\nEnter the usn,Name,Branch, sem,PhoneNo of the student:");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->addr = NULL;
    count++;
    return snode;
}

NODE insertfront() {
    NODE temp;
    temp = create();
    if (start == NULL) {
        return temp;
    }

<<<<<<< HEAD
    temp->addr = start;
=======
    temp->link = start;
    count++;
>>>>>>> 77e2bad2be61bc1c5c6a588815d93bfd58a3b83e
    return temp;
}

NODE deletefront() {
    NODE temp;
    if (start == NULL) {
        printf("\naddred list is empty");
        return NULL;
    }

    if (start->addr == NULL) {
        printf("\nThe Student node with usn:%s is deleted ", start->usn);
        count--;
        free(start);
        return NULL;
    }
    temp = start;
    start = start->addr;
    printf("\nThe Student node with usn:%s is deleted", temp->usn);
    count--;
    free(temp);
    return start;
}

NODE insertend() {
    NODE cur, temp;
    temp = create();

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

NODE deleteend() {
    NODE cur, prev;
    if (start == NULL) {
        printf("\naddred List is empty");
        return NULL;
    }

    if (start->addr == NULL) {
        printf("\nThe student node with the usn:%s is deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }

    prev = NULL;
    cur = start;
    while (cur->addr != NULL) {
        prev = cur;
        cur = cur->addr;
    }

    printf("\nThe student node with the usn:%s is deleted", cur->usn);
    free(cur);
    prev->addr = NULL;
    count--;
    return start;
}

void display() {
    NODE cur;
    int num = 1;

    if (start == NULL) {
        printf("\nNo Contents to display in SLL \n");
        return;
    }
    printf("\nThe contents of SLL: \n");
    cur = start;
    while (cur != NULL) {
        printf("\n|%d| |USN:%s| |Name:%s| |Branch:%s| |Sem:%d| |Ph:%ld|", num, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->addr;
        num++;
    }
    printf("\n No of student nodes is %d \n", count);
}

int main() {
    int ch, i, n;
    while (1) {
        printf("\n--------Menu--------");
        printf("\nEnter your choice for SLL operation \n");
        printf("\n1:Create SLL of Student Nodes");
        printf("\n2:DisplayStatus");
        printf("\n3:InsertAtEnd");
        printf("\n4:DeleteAtEnd");
        printf("\n5:Exit \n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the no of students: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
                start = insertfront();
            break;

        case 2:
            display();
            break;

        case 3:
            start = insertend();
            break;

        case 4:
            start = deleteend();
            break;

        case 5:
            exit(0);

        default:
            printf("\nPlease enter the valid choice");
        }
    }
}