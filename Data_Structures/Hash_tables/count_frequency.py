# A program to count the frequency of elements in an array using a hash table

def count_frequency(arr):
    hash = {}

    for num in arr:
        if num in hash:
            hash[num] += 1
        else:
            hash[num] = 1

    print("Element\tFrequency")
    for num, freq in hash.items():
        print(num, "\t", freq)

arr = [5, 2, 8, 2, 6, 5, 8, 8]
count_frequency(arr)
