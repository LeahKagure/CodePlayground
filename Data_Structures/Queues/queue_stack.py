# Implement a queue using two stacks and perform enqueue and dequeue operations

class Queue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def enqueue(self, value):
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        self.stack1.append(value)
        while self.stack2:
            self.stack1.append(self.stack2.pop())

    def dequeue(self):
        if not self.stack1:
            print("Queue is empty. Cannot dequeue.")
            return
        print("Dequeued element:", self.stack1.pop())

queue = Queue()
queue.enqueue(5)
queue.enqueue(10)
queue.enqueue(15)
queue.dequeue()
queue.enqueue(20)
queue.dequeue()
queue.dequeue()
queue.dequeue()
queue.dequeue()