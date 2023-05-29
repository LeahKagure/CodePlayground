import math

def jump_search(arr, key):
    step = int(math.sqrt(len(arr)))
    prev = 0

    while arr[prev] < key:
        next_ = min(prev + step, len(arr) - 1)

        if arr[next_] >= key:
            break  # element found or crossed

        prev = next_

        if prev >= len(arr):
            return -1  # element not found

    # Linear search in the block
    while arr[prev] < key:
        prev += 1

        if prev == min(len(arr), prev + step):
            return -1  # element not found

    if arr[prev] == key:
        return prev  # element found

    return -1  # element not found

arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
key = 16

position = jump_search(arr, key)

if position != -1:
    print("Element found at position:", position)
else:
    print("Element not found.")
