# Given an array of integers, find the length of the longest subarray with a sum equal to a given target value k

def longest_subarray_sum_k(arr, k):
    max_length = 0
    cumulative_sum = 0
    hash_map = {0: -1}

    for i in range(len(arr)):
        cumulative_sum += arr[i]

        if cumulative_sum == k:
            max_length = i + 1

        if cumulative_sum - k in hash_map:
            length = i - hash_map[cumulative_sum - k]
            if length > max_length:
                max_length = length
        elif cumulative_sum not in hash_map:
            hash_map[cumulative_sum] = i

    return max_length

arr = [3, 1, 2, -2, 4, 6, -3, 2]
k = 4
length = longest_subarray_sum_k(arr, k)
print("Length of longest subarray with sum", k, ":", length)
