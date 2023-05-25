# Write a program to implement a stack and perform the following operations:
# Push an element onto the stack
# Pop an element from the stack
# Check if the stack is empty
# Display the top element of the stack without removing it

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
    
    def top(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        return self.stack[-1]

stack = Stack()

stack.push(10)
stack.push(20)
stack.push(30)

print("Top element:", stack.top())

popped_element = stack.pop()
print("Popped element:", popped_element)
popped_element = stack.pop()
print("Popped element:", popped_element)
popped_element = stack.pop()
print("Popped element:", popped_element)
popped_element = stack.pop()
print("Popped element:", popped_element)
print("\n")
