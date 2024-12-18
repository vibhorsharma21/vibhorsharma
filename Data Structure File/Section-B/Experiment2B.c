#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;  // Initialize the stack as empty

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node
    if (newNode == NULL) {
        printf("Stack overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;  // Assign the data to the node
    newNode->next = top;     // Link the new node to the previous top node
    top = newNode;           // Update the top pointer to the new node
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! The stack is empty.\n");
        return -1;  // Return -1 to indicate an error
    }
    Node* temp = top;       // Store the top node temporarily
    int poppedValue = temp->data;  // Get the value of the top node
    top = top->next;         // Move the top pointer to the next node
    free(temp);              // Free the memory of the popped node
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to peek the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. No elements to peek.\n");
        return -1;  // Return -1 to indicate an error
    }
    return top->data;  // Return the value of the top element
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;  // Move to the next node
    }
    printf("\n");
}

int main() {
    // Test the stack operations
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    display();  // Display the current stack

    pop();
    pop();
    
    display();  // Display the stack after popping two elements

    printf("Top element is: %d\n", peek());  // Peek the top element

    pop();
    pop();
    pop();  // Trying to pop from an empty stack

    display();  // Display the stack after popping all elements

    return 0;}
