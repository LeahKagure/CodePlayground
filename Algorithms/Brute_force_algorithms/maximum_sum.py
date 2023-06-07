# Given an array of integers, find the maximum sum of a subarray of consecutive elements

def max_subarray_sum(arr):
    max_sum = arr[0]
    
    for i in range(len(arr)):
        current_sum = 0
        for j in range(i, len(arr)):
            current_sum += arr[j]
            if current_sum > max_sum:
                max_sum = current_sum
    
    return max_sum

arr = [1, -3, 4, 2, -1, 6, -5]
max_sum = max_subarray_sum(arr)
print("Maximum sum of subarray:", max_sum)
