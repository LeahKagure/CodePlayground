# A program to delete a node at a given position in a doubly linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def create_node(data):
    newNode = Node(data)
    return newNode

def delete_node(head, position):
    if head is None:
        return

    if position == 0:
        new_head = head.next
        if new_head is not None:
            new_head.prev = None
        return new_head

    current = head
    current_position = 0

    while current is not None and current_position < position:
        current = current.next
        current_position += 1

    if current is None:
        return

    current.prev.next = current.next
    if current.next is not None:
        current.next.prev = current.prev

def display_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next

head = create_node(1)
second = create_node(2)
third = create_node(3)

head.next = second
second.prev = head
second.next = third
third.prev = second

print("Original Doubly Linked List:", end=" ")
display_list(head)

position = 1
delete_node(head, position)

print("\nDoubly Linked List after deleting node at position", position, ":", end=" ")
display_list(head)
print("\n")