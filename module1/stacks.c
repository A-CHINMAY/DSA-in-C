#include<stdio.h>
#define STACK_SIZE 5
int top = -1;
int stack[STACK_SIZE];

void push(int item) { 
  if (top == STACK_SIZE-1) { 
     printf("Stack overflow\n") ; 
  } else {
      top = top + 1;
      stack[top] = item;
  }
   
}

void pop(){
    if (top == -1){
        printf(" stack underflow ");
    }else{
        printf("element to be popped is %d",stack[top]);
        top = top - 1;
    }
}

void display(){
    if(top == -1){
        printf(" stack is empty ");
    }else{
        printf("the stack elements are \n");
        for(int i=top ; i>=0 ; i--){
            printf("%d",stack[i]);
        }
    }
}
    

void main(){
    int choice,item;
    for (;;){
        printf("\n1:Push 2:Pop 3:Display 4:Exit \n"); 
        printf("Enter the choice\n"); 
        scanf("%d", &choice); 
 
    switch(choice) {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf(" wrong choice ");
        }
    }
}
