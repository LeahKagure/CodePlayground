# A program to perform interpolation search to find the position of a given element in a sorted array

def interpolation_search(arr, key):
    low = 0
    high = len(arr) - 1

    while low <= high and key >= arr[low] and key <= arr[high]:
        if low == high:
            if arr[low] == key:
                return low  # element found
            return -1  # element not found

        pos = low + ((key - arr[low]) * (high - low)) // (arr[high] - arr[low])

        if arr[pos] == key:
            return pos  # element found

        if arr[pos] < key:
            low = pos + 1  # search the right side
        else:
            high = pos - 1  # search the left side

    return -1  # element not found

arr = [1, 3, 5, 7, 9, 11, 13, 15]
key = 9

position = interpolation_search(arr, key)

if position != -1:
    print("Element found at position:", position)
else:
    print("Element not found.")
