#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char infix[], char prefix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    // Reverse the infix expression
    reverseString(infix);

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (ch == '(') {
            // Change '(' to ')' and vice versa when reversing
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }

        if (isdigit(ch) || isalpha(ch)) {
            prefix[j++] = ch;
        } else if (isOperator(ch)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch)) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                prefix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // Pop '('
            } else {
                printf("Invalid expression - mismatched parentheses\n");
                exit(1);
            }
        } else {
            printf("Invalid character in the expression: %c\n", ch);
            exit(1);
        }
    }

    while (top >= 0) {
        if (stack[top] == '(' || stack[top] == ')') {
            printf("Invalid expression - mismatched parentheses\n");
            exit(1);
        }
        prefix[j++] = stack[top--];
    }

    // Null-terminate the prefix expression
    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
