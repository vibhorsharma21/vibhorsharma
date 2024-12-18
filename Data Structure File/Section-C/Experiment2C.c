#include <stdio.h>
#include <stdlib.h>
// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}
// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Create a new node
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        q->front = q->rear = newNode;
    } else {
        // Otherwise, add the new node to the end of the queue
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued into the queue.\n", value);
}
// Function to remove an element from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicating empty queue
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next; // Move the front pointer to the next node
    if (q->front == NULL) {
        // If the queue is now empty, reset rear to NULL
        q->rear = NULL;
    }
    free(temp); // Free the memory of the dequeued node
    printf("%d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to get the front element of the queue (peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to peek.\n");
        return -1;
    }
    return q->front->data; // Return the front element
}
// Function to display all elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Queue q;
    initializeQueue(&q);  // Initialize the queue
    // Test the queue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    printf("Front element is: %d\n", peek(&q));
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);  // Trying to dequeue when the queue is empty
    display(&q);
    return 0;
}
