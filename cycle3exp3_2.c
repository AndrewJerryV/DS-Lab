#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Recursive function to convert infix to postfix
void infixToPostfixRec(char infix[], int start, int end, char postfix[], int *postfixIndex) {
    if (start > end)
        return;

    // Find the operator with the lowest precedence
    int minPrec = 4;
    int minPrecIndex = -1;
    int openBrackets = 0;

    for (int i = start; i <= end; i++) {
        if (infix[i] == '(') {
            openBrackets++;
        } else if (infix[i] == ')') {
            openBrackets--;
        } else if (isOperator(infix[i]) && openBrackets == 0) {
            int prec = precedence(infix[i]);
            if (prec <= minPrec) {
                minPrec = prec;
                minPrecIndex = i;
            }
        }
    }

    if (minPrecIndex == -1) {
        // No operator found, must be an operand or an expression inside parentheses
        if (infix[start] == '(' && infix[end] == ')') {
            infixToPostfixRec(infix, start + 1, end - 1, postfix, postfixIndex);
        } else {
            // Process multi-digit operands
            while (start <= end && isdigit(infix[start])) {
                postfix[(*postfixIndex)++] = infix[start++];
            }
            postfix[(*postfixIndex)++] = ' '; // Add space to separate operands
        }
    } else {
        // Recur for left and right of the operator
        infixToPostfixRec(infix, start, minPrecIndex - 1, postfix, postfixIndex);
        infixToPostfixRec(infix, minPrecIndex + 1, end, postfix, postfixIndex);

        // Add the operator to postfix
        postfix[(*postfixIndex)++] = infix[minPrecIndex];
        postfix[(*postfixIndex)++] = ' '; // Add space after operator
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int postfixIndex = 0;
    infixToPostfixRec(infix, 0, strlen(infix) - 1, postfix, &postfixIndex);
    postfix[postfixIndex - 1] = '\0'; // Remove the last space and null terminate
}

int main() {
    char infix[100], postfix[100];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}