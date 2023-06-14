# A program to sort an array of integers using the Bucket Sort algorithm
# Assume that the input array contains integers ranging from 0 to 99

SIZE = 10
BUCKET_SIZE = 10

def insert(bucket, value):
    bucket.append(value)

def bucketSort(arr):
    # Create a list of empty buckets
    buckets = [[] for _ in range(BUCKET_SIZE)]

    # Insert elements into buckets
    for value in arr:
        index = value // BUCKET_SIZE
        insert(buckets[index], value)

    # Sort elements within each bucket and update the original array
    index = 0
    for bucket in buckets:
        for value in sorted(bucket):
            arr[index] = value
            index += 1

arr = [75, 15, 30, 45, 60, 90, 20, 10, 80, 25]

print("Original array:")
print(arr)

bucketSort(arr)

print("Sorted array using Bucket Sort:")
print(arr)
