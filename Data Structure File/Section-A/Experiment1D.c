#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Circular link, last node points to head
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  // Circular link, new node points to head
    }

    printf("Inserted %d at the end of the list.\n", value);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void delete(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Case 1: Deleting the head node
    if (temp->data == value) {
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Case 2: Deleting a node other than head
    prev = head;
    temp = head->next;

    while (temp != head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != head && temp != NULL) {
        prev->next = temp->next;
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
    display();

    delete(20);
    display();

    delete(10);
    display();

    delete(50);
    display();

    return 0;
}
