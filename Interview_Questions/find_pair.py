# Given an array of integers, find a pair of elements that sum up to a target value

def find_pair(arr, target):
    seen = set()

    for num in arr:
        complement = target - num

        if complement in seen:
            print("Pair found:", num, complement)
            return  # Return after finding the first pair

        seen.add(num)

    print("No pair found for the given target.")

# Test the function
arr = [1, 2, 3, 4, 5]
target = 10
find_pair(arr, target)
print("\n")
