# Sort an array of integers in ascending order using the insertion sort algorithm

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
arr = [5, 2, 8, 12, 1]
insertion_sort(arr)
print("Sorted Array:", arr)
print("\n")