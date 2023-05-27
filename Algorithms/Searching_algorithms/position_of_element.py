# A program to perform a binary search to find the position of a given element in a sorted array

def binary_search(arr, left, right, key):
    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == key:
            return mid  # element found, return its position

        if arr[mid] < key:
            left = mid + 1  # search the right half
        else:
            right = mid - 1  # search the left half

    return -1  # element not found

arr = [1, 2, 4, 5, 7, 9]
key = 7

position = binary_search(arr, 0, len(arr) - 1, key)

if position != -1:
    print("Element found at position:", position)
else:
    print("Element not found.")
