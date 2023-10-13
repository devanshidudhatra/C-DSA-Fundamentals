#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure to represent a stack
struct Stack {
    int top;                // Index of the top element
    unsigned capacity;      // Maximum capacity of the stack
    char* array;            // Array to store stack elements
};

// Function to create a new stack with the specified capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;

    stack->capacity = capacity;
    stack->top = -1;        // Initialize top to -1 to represent an empty stack
    stack->array = (char*)malloc(capacity * sizeof(char));
    if (!stack->array)      // Check if memory allocation failed
        return NULL;

    return stack;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %c\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop and return the top element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0'; // Return a sentinel value to indicate an error
    }
    return stack->array[stack->top--];
}

// Function to check if the given expression is balanced
bool isBalanced(char* expression) {
    struct Stack* stack = createStack(strlen(expression));

    for (int i = 0; expression[i]; i++) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (isEmpty(stack)) {
                // There's a closing parenthesis without a matching opening parenthesis
                free(stack->array);
                free(stack);
                return false;
            }

            char topChar = pop(stack);

            // Check if the current closing parenthesis matches the top of the stack
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == ']' && topChar != '[') ||
                (currentChar == '}' && topChar != '{')) {
                free(stack->array);
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack); // If stack is empty, the expression is balanced
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
