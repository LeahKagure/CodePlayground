# A program to sort an array of integers using the Counting Sort algorithm
# Assume that the input array contains integers ranging from 0 to 9

SIZE = 10
RANGE = 10

def countingSort(arr):
    # Create a counting array of size RANGE and initialize all elements to 0
    count = [0] * RANGE

    # Calculate the frequency of each element in the input array
    for num in arr:
        count[num] += 1

    # Modify the counting array to contain the actual position of each element in the sorted array
    for i in range(1, RANGE):
        count[i] += count[i - 1]

    # Create a temporary array to store the sorted elements
    output = [0] * len(arr)

    # Place each element in its correct position in the sorted array
    for num in reversed(arr):
        output[count[num] - 1] = num
        count[num] -= 1

    # Copy the sorted elements back to the original array
    for i in range(len(arr)):
        arr[i] = output[i]

arr = [4, 2, 6, 3, 1, 9, 8, 0, 7, 5]

print("Original array:")
print(arr)

countingSort(arr)

print("Sorted array using Counting Sort:")
print(arr)
