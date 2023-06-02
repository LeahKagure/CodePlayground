# A program to reverse the elements of a queue

def reverse_queue(queue):
    if not queue:
        return

    front = queue.pop(0)
    reverse_queue(queue)
    queue.append(front)

queue = [5, 10, 15, 20]
reverse_queue(queue)
print("Reversed Queue:", queue)
