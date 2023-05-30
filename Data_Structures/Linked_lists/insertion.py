# Write a program that inserts a new node at the beginning of a singly linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert_at_beginning(head, newData):
    newNode = Node(newData)
    newNode.next = head
    return newNode

def display_linked_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next

head = None
head = insert_at_beginning(head, 1)
head = insert_at_beginning(head, 2)
head = insert_at_beginning(head, 3)

print("Linked List after insertion:", end=" ")
display_linked_list(head)
print("\n")