# Write a program to implement a stack and perform the following operations:
# - Push an element onto the stack
# - Pop an element from the stack
# - Find the minimum element in the stack in 0(1) time complexity

class Stack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    
    def is_empty(self):
        return len(self.stack) == 0
    
    def is_full(self):
        return False
    
    def push(self, element):
        self.stack.append(element)

        if self.is_empty() or element < self.get_minimum():
            self.min_stack.append(element)
        else:
            self.min_stack.append(self.min_stack[-1])
    
    def pop(self):
        if self.is_empty():
            print("Stack is empty. Cannot pop element.")
            return None
        
        self.min_stack.pop()
        return self.stack.pop()

    def get_minimum(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        
        return self.min_stack[len(self.min_stack) - 1]

stack = Stack()

stack.push(5)
stack.push(3)
stack.push(8)
stack.push(2)
stack.push(6)

print("Minimum element:", stack.get_minimum())

stack.pop()
stack.pop()

print("Minimum element:", stack.get_minimum())
