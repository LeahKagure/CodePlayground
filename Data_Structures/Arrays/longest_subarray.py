# Given an array of integers, find the longest increasing subarray (contiguous elements) and return its length

def longest_increasing_subarray(arr):
    maxLength = 1
    currentLength = 1

    for i in range(1, len(arr)):
        if arr[i] > arr[i - 1]:
            currentLength += 1
        else:
            if currentLength > maxLength:
                maxLength = currentLength
            currentLength = 1

    if currentLength > maxLength:
        maxLength = currentLength

    return maxLength

arr = [1, 2, 3, 2, 5, 7, 8, 9, 2, 4]
length = longest_increasing_subarray(arr)
print("Longest increasing subarray length:", length)
print("\n")
