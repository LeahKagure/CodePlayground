# Given a set of characters and their frequencies, build a binary tree-based code such that characters
# with higher frequencies are assigned shorter code

class Node:
    def __init__(self, data, freq):
        self.data = data
        self.freq = freq
        self.left = None
        self.right = None

def is_leaf(root):
    return not root.left and not root.right

def print_codes(root, arr, top):
    if root.left:
        arr[top] = 0
        print_codes(root.left, arr, top + 1)

    if root.right:
        arr[top] = 1
        print_codes(root.right, arr, top + 1)

    if is_leaf(root):
        print(root.data, end=": ")
        for i in range(top):
            print(arr[i], end="")
        print()

def huffman_codes(data, freq, size):
    min_heap = []
    for i in range(size):
        min_heap.append(Node(data[i], freq[i]))

    while len(min_heap) > 1:
        min_heap.sort(key=lambda x: x.freq)
        left = min_heap.pop()
        right = min_heap.pop()

        top = Node('$', left.freq + right.freq)
        top.left = left
        top.right = right

        min_heap.append(top)

    arr = [None] * size
    print_codes(min_heap[0], arr, 0)

data = ['a', 'b', 'c', 'd', 'e']
freq = [5, 9, 12, 13, 16]
size = len(data)

huffman_codes(data, freq, size)
