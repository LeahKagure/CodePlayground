# Given a list of activities with their start and finish times, select the maximum of
# non-overlapping activities that can be performed

def print_max_activities(start, finish):
    n = len(start)
    print("Selected activities:", end=" ")
    i = 0
    print(i, end=" ")

    for j in range(1, n):
        if start[j] >= finish[i]:
            print(j, end=" ")
            i = j

start = [1, 3, 0, 5, 8, 5]
finish = [2, 4, 6, 7, 9, 9]
print_max_activities(start, finish)
print("\n")