#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct {
    int data;
    int next;
} Node;
Node linkedList[MAX_SIZE];
int head = -1;
void initializeList() {
    for (int i = 0; i < MAX_SIZE; i++) {
        linkedList[i].next = -1;
    }
}
void insert(int value) {
    int newNodeIndex = -1;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (linkedList[i].next == -1 && linkedList[i].data == 0) {
            newNodeIndex = i;
            break;
        }
    }
    if (newNodeIndex == -1) {
        printf("List is full!\n");
        return;
    }
    linkedList[newNodeIndex].data = value;
    linkedList[newNodeIndex].next = -1;
    if (head == -1) {
        head = newNodeIndex;
    } else {
        int temp = head;
        while (linkedList[temp].next != -1) {
            temp = linkedList[temp].next;
        }
        linkedList[temp].next = newNodeIndex;
    }
    printf("Inserted %d into the list.\n", value);
}
void display() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    int temp = head;
    printf("Linked List: ");
    while (temp != -1) {
        printf("%d -> ", linkedList[temp].data);
        temp = linkedList[temp].next;
    }
    printf("NULL\n");
}
void delete(int value) {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }
    int temp = head;
    int prev = -1;

    while (temp != -1 && linkedList[temp].data != value) {
        prev = temp;
        temp = linkedList[temp].next;
    }

    if (temp != -1) {
        if (prev == -1) {
            head = linkedList[temp].next;
        } else {
            linkedList[prev].next = linkedList[temp].next;
        }
        linkedList[temp].data = 0;
        linkedList[temp].next = -1;
        printf("Deleted %d from the list.\n", value);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}
int main() {
    initializeList();
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();

    delete(20);
    display();

    delete(50);
    display();

    return 0;
}
