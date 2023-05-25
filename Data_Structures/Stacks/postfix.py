# Write a program to evaluate a postfix expression using a stack
# The postfix expression will only contain integer operands and the following operators: '+','-','*','/'

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

def evaluate_postfix(postfix):
    stack = Stack()

    for char in postfix:
        if char.isdigit():
            stack.push(int(char))
        else:
            operand2 = stack.pop()
            operand1 = stack.pop()

            if char == '+':
                stack.push(operand1 + operand2)
            elif char == '-':
                stack.push(operand1 - operand2)
            elif char == '*':
                stack.push(operand1 * operand2)
            elif char == '/':
                stack.push(operand1 / operand2)

    return stack.pop()

postfix = "52+83-*4/"

result = evaluate_postfix(postfix)
print("Result:", result)
print("\n")