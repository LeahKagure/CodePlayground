# Write a recursive function to find the sum of elements in an array

def sum_array(arr, n):
    if n == 0:
        return 0
    else:
        return arr[n - 1] + sum_array(arr, n - 1)

arr = [2, 4, 6, 8, 10]
n = len(arr)
result = sum_array(arr, n)
print("Sum of elements in the array is", result)