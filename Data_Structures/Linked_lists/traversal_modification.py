# A program to traverse through the list and double the value of each node

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to insert a node at the end of the linked list
def insertAtEnd(head, data):
    newNode = Node(data)
    if head is None:
        head = newNode
        return head
    last = head
    while last.next is not None:
        last = last.next
    last.next = newNode
    return head

# Function to display the linked list
def displayList(head):
    if head is None:
        print("Linked list is empty.")
        return
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Function to traverse and modify the linked list by doubling the value of each node
def doubleList(head):
    current = head
    while current is not None:
        current.data *= 2
        current = current.next

# Main function
def main():
    head = None
    head = insertAtEnd(head, 1)
    head = insertAtEnd(head, 2)
    head = insertAtEnd(head, 3)
    head = insertAtEnd(head, 4)
    head = insertAtEnd(head, 5)

    print("Original Linked List:", end=" ")
    displayList(head)

    doubleList(head)

    print("Modified Linked List (doubled values):", end=" ")
    displayList(head)

if __name__ == '__main__':
    main()
