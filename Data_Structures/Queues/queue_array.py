# A program to implement a queue using an array and perform basic operations like enqueue and dequeue

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if not self.queue:
            print("Queue is empty. Cannot dequeue.")
            return
        print("Dequeued element:", self.queue.pop(0))

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