// A program to delete a node at a given position in a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;

    if (position == 0) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    int currentPosition = 0;

    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original Doubly Linked List: ");
    displayList(head);

    int position = 1;
    deleteNode(&head, position);

    printf("\nDoubly Linked List after deleting node at position %d: ", position);
    displayList(head);
    printf("\n\n");

    return 0;
}
