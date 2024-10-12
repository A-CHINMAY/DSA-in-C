#include <stdio.h>
#include <stdlib.h>
int *a,size,top = -1;

void push() {
    int ele;
    if (top == size - 1) {
        printf("Stack is overflow\n");
        printf("Increasing the stack size by twice\n");
        size = 2 * size;
        a = (int *)realloc(a, size * sizeof(int));
        top = top + 1;
        printf("Enter the element to Push\n");
        scanf("%d", &ele);
        *(a + top) = ele;
    }
    else {
        top = top + 1;
        printf("Enter the element to Push\n");
        scanf("%d", &ele);
        *(a + top) = ele;
    }
}
void pop() {
    int ele;
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    else {
        ele = *(a + top);
        printf("The deleted element is %d", ele);
        top = top - 1;
    }
}
void display() {
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    else {
        printf("The contents of Stack are\n");
        for (int i = top; i >= 0; i--)
            printf("%d\t", *(a + i));
    }
}

int main()
{
    int ch;
    printf("Enter the Size of the Stack\n");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));
    for (;;) {
        printf("1.Push 2.display 3.pop 4.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
                
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:  
                free(a);
                exit(0);
        }
    }
}