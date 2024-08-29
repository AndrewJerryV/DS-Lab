#include <stdio.h>
#include <string.h>

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j=0, stackTop = 0;
    char stack[100]; 
    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') { 
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++stackTop] = infix[i]; 
        } else if (infix[i] == ')') {
            while (stackTop >= 0 && stack[stackTop] != '(') {
                postfix[j++] = stack[stackTop--];
            }
            stackTop--; 
        } else { 
            while (stackTop >= 0 && precedence(stack[stackTop]) >= precedence(infix[i]) && stack[stackTop] != '(') {
                postfix[j++] = stack[stackTop--]; 
            }
            stack[++stackTop] = infix[i]; 
        }
    }
    while (stackTop >= 0) {
        postfix[j++] = stack[stackTop--]; 
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
