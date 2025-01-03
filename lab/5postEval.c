#include <stdio.h>
#include <math.h>
#define MAX 50
float stack[MAX];
int top = -1;

void push(int *top, float value) {
    (*top)++;
    stack[*top] = value;
}

float pop(int *top) {
    float value = stack[*top];
    (*top)--;
    return value;
}

float operate(float opr1, float opr2, char symbol) {
    switch (symbol) {
        case '+':
            return opr1 + opr2;
        case '-':
            return opr1 - opr2;
        case '*':
            return opr1 * opr2;
        case '/':
            return opr1 / opr2;
        case '%':
            return (int)opr1 % (int)opr2;
        case '^':
            return pow(opr1, opr2);
        case '$':
            return (opr1 > opr2) ? opr1 : opr2;
        default:
            printf("Unknown operator: %c\n", symbol);
            return 0;
    }
}

float postfix_evaluate(char postfix[], int *s) {
    int i;
    char symbol;
    float opr1, opr2, res, value;

    for (i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            push(s, symbol - '0'); // Convert char digit to integer
        }
        else if (isalpha(symbol)) {
            printf("Enter the value for %c: ", symbol);
            scanf("%f", &value);
            push(s, value);
        }
        else {
            opr2 = pop(s);
            opr1 = pop(s);
            res = operate(opr1, opr2, symbol);
            push(s, res);
        }
    }
    return pop(s);
}

int main() {
    char postfix[MAX];
    float result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = postfix_evaluate(postfix, &top);

    printf("Result of postfix expression evaluation: %.2f\n", result);
}
