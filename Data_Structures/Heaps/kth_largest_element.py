# Given an array of integers and an integer k, find the kth largest element in the array using a heap

import heapq

def find_kth_largest(nums, k):
    return heapq.nlargest(k, nums)[-1]

nums = [3, 1, 4, 2, 5]
k = 2

kth_largest = find_kth_largest(nums, k)
print("Kth largest element:", kth_largest)
