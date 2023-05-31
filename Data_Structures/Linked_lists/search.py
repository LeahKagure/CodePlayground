# A program to search for a specific element in a circular linked list and return its position

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to insert a node at the end of the circular linked list
def insertAtEnd(head, data):
    newNode = Node(data)
    if head is None:
        head = newNode
        head.next = head
        return head
    last = head
    while last.next != head:
        last = last.next
    last.next = newNode
    newNode.next = head
    return head

# Function to display the circular linked list
def displayList(head):
    if head is None:
        print("Circular linked list is empty.")
        return
    temp = head
    while True:
        print(temp.data, end=" ")
        temp = temp.next
        if temp == head:
            break
    print()

# Function to search for an element in a circular linked list
def searchElement(head, key):
    if head is None:
        return -1
    current = head
    position = 0
    while True:
        if current.data == key:
            return position
        current = current.next
        position += 1
        if current == head:
            break
    return -1

# Main function
def main():
    head = None
    head = insertAtEnd(head, 1)
    head = insertAtEnd(head, 2)
    head = insertAtEnd(head, 3)
    head = insertAtEnd(head, 4)
    head = insertAtEnd(head, 5)

    print("Circular Linked List:", end=" ")
    displayList(head)

    key = 3
    position = searchElement(head, key)
    if position == -1:
        print("Element", key, "not found in the circular linked list.")
    else:
        print("Element", key, "found at position", position, "in the circular linked list.")

if __name__ == '__main__':
    main()
