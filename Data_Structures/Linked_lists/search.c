// A program to search for a specific element in a circular linked list and return its position

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to search for an element in a circular linked list
int searchElement(struct Node* head, int key) {
    if (head == NULL) {
        return -1;
    }
    struct Node* current = head;
    int position = 0;
    do {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != head);
    return -1;
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Circular Linked List: ");
    displayList(head);

    int key = 3;
    int position = searchElement(head, key);
    if (position == -1) {
        printf("Element %d not found in the circular linked list.\n", key);
    } else {
        printf("Element %d found at position %d in the circular linked list.\n", key, position);
    }

    printf("\n");
    return 0;
}
