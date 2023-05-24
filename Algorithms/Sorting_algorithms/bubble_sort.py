# Sort an array of integers in ascending order using the bubble sort algorithm

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = [5,2,8,12,1]
bubble_sort(arr)
print("Sorted Array:", arr)
print("\n")