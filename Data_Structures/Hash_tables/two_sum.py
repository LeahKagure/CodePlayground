# Given an array of integers and a target value, find two numbers in the array that sum up to the target value

def two_sum(nums, target):
    hash_map = {}

    for i, num in enumerate(nums):
        complement = target - num
        if complement in hash_map:
            return [hash_map[complement], i]
        hash_map[num] = i

    return []

nums = [2, 7, 11, 15]
target = 9
result = two_sum(nums, target)
print("Indices:", result[0], result[1])
