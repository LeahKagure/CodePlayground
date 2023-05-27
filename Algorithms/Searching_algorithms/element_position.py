# // A program to perform a linear search to find the position of a given element in an array

def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # element found, return its position
    return -1  # element not found

arr = [4, 2, 7, 1, 9, 5]
key = 7

position = linear_search(arr, key)

if position != -1:
    print("Element found at position:", position)
else:
    print("Element not found.")
print("\n")