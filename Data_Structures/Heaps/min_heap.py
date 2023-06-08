# Create a min heap data structure and implement insertions and extraction operations

class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        self.heap.append(value)
        index = len(self.heap) - 1
        while index != 0 and self.heap[(index - 1) // 2] > self.heap[index]:
            self.heap[(index - 1) // 2], self.heap[index] = self.heap[index], self.heap[(index - 1) // 2]
            index = (index - 1) // 2

    def extract_min(self):
        if not self.heap:
            print("Heap is empty. Cannot extract.")
            return None

        min_val = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()

        index = 0
        while True:
            smallest = index
            left = 2 * index + 1
            right = 2 * index + 2

            if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
                smallest = left

            if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
                smallest = right

            if smallest != index:
                self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
                index = smallest
            else:
                break

        return min_val

heap = MinHeap()
heap.insert(4)
heap.insert(2)
heap.insert(7)
heap.insert(5)
print("Extracted min:", heap.extract_min())
print("Extracted min:", heap.extract_min())
