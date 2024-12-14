#include <stdio.h>
#include <string.h>
char stack[50];
int top = -1;

void push(char c) {
    top = top + 1;
    stack[top] = c;
}

char pop() {
    if (top == -1){
        printf(" underflow ");
    }
    char temp = stack[top];
    top = top - 1;
    return temp;
}


int priority(char c) {
    switch (c) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
        case '$':
            return 4;
        default:
            return -1;
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol, temp;
    push('#');

    for (i = 0; i < strlen(infix); i++){
        symbol = infix[i];

        if (symbol == '(') {
            push(symbol);
        }
        else if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == ')') {
            while ((temp = pop()) != '('){
                postfix[j++] = temp;
            }
        }
        else {
            while (priority(stack[top]) >= priority(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (stack[top] != '#') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void main() {
    char infix[50], postfix[50];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);
}