#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (expression[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char expression[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", expression);
    printf("Result: %d\n", evaluatePostfix(expression));
    return 0;
}
