#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Define the maximum size of the circular queue
// Define the structure for the circular queue
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;
// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1);
}
// Function to check if the queue is full
int isFull(Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}
// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {
        // If the queue is empty, both front and rear will point to the first element
        q->front = 0;
    }
    // Move rear to the next position (circular increment)
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicating empty queue
    }
    int dequeuedValue = q->arr[q->front];
    if (q->front == q->rear) {
        // If only one element is left, reset the queue to empty state
        q->front = q->rear = -1;
    } else {
        // Move front to the next position (circular increment)
        q->front = (q->front + 1) % MAX;
    }
    printf("%d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}
// Function to get the front element of the queue (peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to peek.\n");
        return -1;
    }
    return q->arr[q->front]; // Return the front element
}
// Function to display all elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;  // Circular increment
    }
    printf("%d\n", q->arr[q->rear]); // Print the last element
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
    enqueue(&q, 60);  // Trying to enqueue when the queue is full
    dequeue(&q);
    dequeue(&q);
    display(&q);
    printf("Front element is: %d\n", peek(&q));
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);  // Trying to dequeue when the queue is empty
    display(&q);
    return 0;}
