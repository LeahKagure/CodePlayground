# Sort an array of integers in ascending order using the selection sort algorithm

def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

arr = [5, 2, 8, 12, 1]
selection_sort(arr)
print("Sorted Array:", arr)
print("\n")