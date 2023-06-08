# Given a char array representing tasks CPU need to do, where each task is represented by a character
# and has a non-negative cooling interval n, find the least number of intervals the CPU needs to finish
# all tasks.

def least_interval(tasks, n):
    char_counts = [0] * 26
    max_count = 0
    max_count_tasks = 0

    for task in tasks:
        char_counts[ord(task) - ord('A')] += 1
        if char_counts[ord(task) - ord('A')] == max_count:
            max_count_tasks += 1
        elif char_counts[ord(task) - ord('A')] > max_count:
            max_count = char_counts[ord(task) - ord('A')]
            max_count_tasks = 1

    partitions = max_count - 1
    empty_slots = partitions * (n - max_count_tasks + 1)
    available_tasks = len(tasks) - max_count * max_count_tasks
    idle_slots = max(empty_slots - available_tasks, 0)

    return len(tasks) + idle_slots

tasks = ['A', 'A', 'A', 'B', 'B', 'B']
n = 2

min_intervals = least_interval(tasks, n)
print("Least number of intervals:", min_intervals)
