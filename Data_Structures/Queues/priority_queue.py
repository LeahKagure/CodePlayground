# A priority queue using an array and perform enqueue and dequeue operations
# based on priority assigned to elements

class PriorityQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, value, priority):
        self.queue.append((value, priority))
        self.queue.sort(key=lambda x: x[1])

    def dequeue(self):
        if not self.queue:
            print("Priority queue is empty. Cannot dequeue.")
            return
        print("Dequeued element:", self.queue.pop(0)[0])

priority_queue = PriorityQueue()
priority_queue.enqueue("Task 1", 3)
priority_queue.enqueue("Task 2", 1)
priority_queue.enqueue("Task 3", 2)
priority_queue.dequeue()
priority_queue.enqueue("Task 4", 1)
priority_queue.dequeue()
priority_queue.dequeue()
priority_queue.dequeue()
priority_queue.dequeue()