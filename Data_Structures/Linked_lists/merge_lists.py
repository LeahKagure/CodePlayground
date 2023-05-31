# A program to merge two sorted singly linked lists into a single sorted list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to create a new node
def createNode(data):
    newNode = Node(data)
    return newNode

# Function to insert a node at the end of the linked list
def insertAtEnd(head, data):
    newNode = createNode(data)
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

# Function to merge two sorted linked lists into a single sorted list
def mergeLists(list1, list2):
    if list1 is None:
        return list2
    if list2 is None:
        return list1
    result = None
    if list1.data <= list2.data:
        result = list1
        result.next = mergeLists(list1.next, list2)
    else:
        result = list2
        result.next = mergeLists(list1, list2.next)
    return result

if __name__ == '__main__':
    list1 = None
    list1 = insertAtEnd(list1, 1)
    list1 = insertAtEnd(list1, 3)
    list1 = insertAtEnd(list1, 5)

    list2 = None
    list2 = insertAtEnd(list2, 2)
    list2 = insertAtEnd(list2, 4)
    list2 = insertAtEnd(list2, 6)

    print("List 1:", end=" ")
    displayList(list1)
    print("List 2:", end=" ")
    displayList(list2)

    mergedList = mergeLists(list1, list2)

    print("Merged List:", end=" ")
    displayList(mergedList)
