# Given an array of integers, find the total number of subarrays that sum up to a target value K

def subarray_sum(nums, k):
    count = 0
    prefix_sum = 0
    sum_map = {0: 1}

    for num in nums:
        prefix_sum += num
        count += sum_map.get(prefix_sum - k, 0)
        sum_map[prefix_sum] = sum_map.get(prefix_sum, 0) + 1

    return count

nums = [1, 1, 1]
k = 2

result = subarray_sum(nums, k)
print("Number of subarrays with sum", k, ":", result)
