#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Maximum size of the queue
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;
// Function to initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;}
// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}
// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return; }
    if (queue->front == -1) {
        queue->front = 0;  // Set front to 0 when the first element is added
    }
    queue->arr[++(queue->rear)] = value;  // Increment rear and add element
    printf("%d enqueued into the queue.\n", value);
}
// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Return -1 to indicate empty queue
    }
    int dequeuedValue = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;  // Reset queue to empty state
    } else {
        queue->front++;  // Move front pointer to the next element
    }
    printf("%d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}
// Function to peek at the front element of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No elements to peek.\n");
        return -1;
    }
    return queue->arr[queue->front];  // Return the front element
}
// Function to display all elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;}
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}int main() {
    Queue queue;
    initializeQueue(&queue);  // Initialize the queue

    // Test the queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    display(&queue);
    enqueue(&queue, 60);  // Trying to enqueue when the queue is full
    dequeue(&queue);
    dequeue(&queue);

    display(&queue);
    printf("Front element is: %d\n", peek(&queue));
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);  // Trying to dequeue when the queue is empty
    display(&queue);
    return 0;
}
