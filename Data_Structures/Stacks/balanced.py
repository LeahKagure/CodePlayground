# Write a program to check if a given string of parantheses is balanced or not using a stack
# The string will only contain parantheses characters '(' and ')'

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
    
def is_balanced(parentheses):
    stack = Stack()

    for char in parentheses:
        if char == '(':
            stack.push(char)
        elif char == ')':
            if stack.is_empty():
                return False
            stack.pop()

    return stack.is_empty()

parentheses1 = "(()))"
parentheses2 = "((()))"

if is_balanced(parentheses1):
    print("Parentheses 1 are balanced.")
else:
    print("Parentheses 1 are not balanced.")

if is_balanced(parentheses2):
    print("Parentheses 2 are balanced.")
else:
    print("Parentheses 2 are not balanced.")
print("\n")