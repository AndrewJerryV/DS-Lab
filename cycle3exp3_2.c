#include <stdio.h>
#include <string.h>

char postfix[100];  
int postfixIndex = 0;  

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* expr, int start, int end) {
    if (start == end) { 
        postfix[postfixIndex++] = expr[start];
        return;
    }

    int minPrec = 100;
    int mainOpPos = -1; 
    int openBrackets = 0; 
   
    for (int i = start; i <= end; i++) {
        if (expr[i] == '(') {
            openBrackets++;
        } else if (expr[i] == ')') {
            openBrackets--;
        } else if (openBrackets == 0 && isOperator(expr[i]) && precedence(expr[i]) <= minPrec) {
            minPrec = precedence(expr[i]);
            mainOpPos = i;
        }
    }

    if (mainOpPos == -1) {
        if (expr[start] == '(' && expr[end] == ')') {
            infixToPostfix(expr, start + 1, end - 1); 
        }
        return;
    }

    infixToPostfix(expr, start, mainOpPos - 1);
    infixToPostfix(expr, mainOpPos + 1, end);
    postfix[postfixIndex++] = expr[mainOpPos];
}

int main() {
    char expr[100];  

    printf("Enter an infix expression (with or without parentheses): ");
    scanf("%s", expr);

    int n = strlen(expr); 
    infixToPostfix(expr, 0, n - 1);
    postfix[postfixIndex] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
