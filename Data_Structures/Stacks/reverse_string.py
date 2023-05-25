class Stack:
    def __init__(self):
        self.stack = []
    
    def is_empty(self):
        return len(self.stack) == 0
    
    def is_full(self):
        return False
    
    def push(self, element):
        self.stack.append(element)
    
    def pop(self):
        if self.is_empty():
            print("Stack is empty. Cannot pop element.")
            return None
        return self.stack.pop()

def reverse_string(string):
    stack = Stack()

    for char in string:
        stack.push(char)

    for i in range(len(string)):
        string[i] = stack.pop()

    return string

string = list("Hello, World!")
print("Original string:", "".join(string))

reversed_string = reverse_string(string)
print("Reversed string:", "".join(reversed_string))
print("\n")