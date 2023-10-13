#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure to represent a stack
struct Stack {
    int top;                // Index of the top element
    unsigned capacity;      // Maximum capacity of the stack
    char array[MAX_SIZE];   // Array to store stack elements
};

// Function to create and initialize a stack
struct Stack createStack() {
    struct Stack stack;
    stack.capacity = MAX_SIZE;
    stack.top = -1;        // Initialize top to -1 to represent an empty stack
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack stack) {
    return stack.top == stack.capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack stack) {
    return stack.top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item) {
    if (isFull(*stack)) {
        return; // Stack is full; do nothing
    }
    stack->array[++stack->top] = item; // Increment top and add the item
}

// Function to pop and return the top element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(*stack)) {
        return '\0'; // Stack is empty; return null character for error
    }
    return stack->array[stack->top--]; // Decrement top and return the item
}

// Function to reverse a string using a stack
void reverseString(char *input) {
    int length = strlen(input); // Calculate the length of the input string
    struct Stack stack = createStack(); // Create an empty stack

    // Push each character of the input string onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    // Pop characters from the stack to reverse the input string
    for (int i = 0; i < length; i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_SIZE]; // Declare an array to store user input

    printf("Enter a string: ");
    scanf("%s", input); // Read a string from the user

    reverseString(input); // Reverse the input string

    printf("Reversed string: %s\n", input); // Print the reversed string

    return 0;
}
