def count_occurrences(arr, target):
    count = 0
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            count += 1
            i = mid - 1
            while i >= 0 and arr[i] == target:
                count += 1
                i -= 1

            i = mid + 1
            while i < len(arr) and arr[i] == target:
                count += 1
                i += 1

            return count
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return count

arr = [2, 3, 5, 5, 5, 7, 8, 8, 9]
target = 5
count = count_occurrences(arr, target)
print("Occurrences of", target, ":", count)
print("\n")