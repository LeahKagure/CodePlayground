# Reverse an array without using any additional data structures

def reverse_array(arr):
    start = 0
    end = len(arr)-1

    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

arr = [10, 20, 30, 40, 50, 60]
print("\n")
print("Original Array:", arr)
reverse_array(arr)
print("Reversed Array:", arr)