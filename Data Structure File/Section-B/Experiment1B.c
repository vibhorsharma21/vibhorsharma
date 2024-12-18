#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;  // Initially, the stack is empty
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d onto the stack.\n", value);
        return;
    }
    stack->arr[++(stack->top)] = value;  // Increment top and insert value
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop from the stack.\n");
        return -1;  // Return -1 to indicate stack underflow
    }
    int poppedValue = stack->arr[(stack->top)--];  // Return the top element and decrement top
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No elements to peek.\n");
        return -1;  // Return -1 to indicate stack underflow
    }
    return stack->arr[stack->top];  // Return the top element
}

// Function to display the elements of the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);  // Initialize the stack

    // Test the stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    display(&stack);

    push(&stack, 60);  // Trying to push when the stack is full

    pop(&stack);
    pop(&stack);

    display(&stack);

    printf("Top element is: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);  // Trying to pop when the stack is empty

    display(&stack);

    return 0;
}

