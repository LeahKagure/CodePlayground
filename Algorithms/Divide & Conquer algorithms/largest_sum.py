# Given an array of integers, find the contiguoug subarray with the largest sum and return the sum

def max_subarray_sum(arr, left, right):
    # Base case: if the array contains only one element
    if left == right:
        return arr[left]

    # Divide the array into two halves
    mid = (left + right) // 2

    # Recursively find the maximum subarray sum in the left half
    left_max_sum = max_subarray_sum(arr, left, mid)

    # Recursively find the maximum subarray sum in the right half
    right_max_sum = max_subarray_sum(arr, mid + 1, right)

    # Find the maximum subarray sum that crosses the midpoint
    cross_max_sum = 0
    left_sum = float('-inf')  # Initialize with negative infinity
    right_sum = float('-inf')  # Initialize with negative infinity

    # Find the maximum sum of the left part of the subarray
    for i in range(mid, left - 1, -1):
        cross_max_sum += arr[i]
        if cross_max_sum > left_sum:
            left_sum = cross_max_sum

    cross_max_sum = 0  # Reset cross_max_sum

    # Find the maximum sum of the right part of the subarray
    for i in range(mid + 1, right + 1):
        cross_max_sum += arr[i]
        if cross_max_sum > right_sum:
            right_sum = cross_max_sum

    # Return the maximum of the three sums
    max_sum = max(left_max_sum, right_max_sum, left_sum + right_sum)
    return max_sum

arr = [-2, -3, 4, -1, -2, 1, 5, -3]
n = len(arr)

max_sum = max_subarray_sum(arr, 0, n - 1)
print("Maximum subarray sum:", max_sum)
