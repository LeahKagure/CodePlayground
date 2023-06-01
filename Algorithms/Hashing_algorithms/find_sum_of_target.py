# Given an array of integers, find two numbers that sum up to a given target value

def find_two_sum(arr, target):
    hash = {}

    for num in arr:
        complement = target - num
        if complement in hash:
            print(f"Pair found: {num} + {complement} = {target}")
            return True
        hash[num] = True

    print("Pair not found!")
    return False

arr = [2, 4, 7, 11, 15]
target = 9

find_two_sum(arr, target)
