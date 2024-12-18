#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("Inserted %d at the end of the list.\n", value);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    printf("Circular Doubly Linked List (Backward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head);
    printf("(back to head)\n");
}

void delete(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;

    // Case 1: Deleting the head node
    if (temp->data == value) {
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            Node* last = head->prev;
            head = temp->next;
            head->prev = last;
            last->next = head;
            free(temp);
        }
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Case 2: Deleting a node other than the head node
    temp = head->next;
    while (temp != head && temp->data != value) {
        temp = temp->next;
    }

    if (temp != head) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("Deleted %d from the list.\n", value);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    displayForward();
    displayBackward();
    delete(20);
    displayForward();
    displayBackward();
    delete(10);
    displayForward();
    displayBackward();
    delete(50);
    displayForward();
    displayBackward();
    return 0;
}
