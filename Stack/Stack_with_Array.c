// Implementation of stack with array

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

// structure to represent a stack
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity. It initializes size of stack at 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(stack -> capacity * sizeof(int));
    return stack;
};

// Stack is full when top is equal to last index
int isFull(struct Stack* stack){
    return stack -> top == stack -> capacity-1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack){
    return stack -> top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item){
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] =item;
    printf("\n%d pushed to stack  " , item);
}

// Function to remove an item from stack. it decreases top by 1
int pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top];
}

// Main Program
int main(){
    struct Stack* stack = createStack(100);

    push(stack,10);
    push(stack,20);
    push(stack,30);

    printf("\n%d popped from stack  " , pop(stack));
    printf("\n%d peek element from stack  " , peek(stack));

    return 0;
}