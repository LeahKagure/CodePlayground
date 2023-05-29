# A program to perform an exponential search to find the position of a given element in a sorted array

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

def exponential_search(arr, key):
    if arr[0] == key:
        return 0  # element found at the beginning

    i = 1
    while i < len(arr) and arr[i] <= key:
        i *= 2  # double the position for each iteration

    return binary_search(arr, i // 2, min(i, len(arr) - 1), key)

arr = [2, 4, 8, 16, 32, 64, 128, 256, 512]
key = 64

position = exponential_search(arr, key)

if position != -1:
    print("Element found at position:", position)
else:
    print("Element not found.")
