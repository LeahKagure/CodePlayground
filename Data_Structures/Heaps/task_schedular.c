// Given a char array representing tasks CPU need to do, where each task is represented by a character
// and has a non-negative cooling interval n, find the least number of intervals the CPU needs to finish
// all tasks.

#include <stdio.h>
#include <stdlib.h>

int leastInterval(char* tasks, int n) {
    int charCounts[26] = {0};
    int maxCount = 0;
    int maxCountTasks = 0;

    for (int i = 0; tasks[i] != '\0'; i++) {
        charCounts[tasks[i] - 'A']++;
        if (charCounts[tasks[i] - 'A'] == maxCount)
            maxCountTasks++;
        else if (charCounts[tasks[i] - 'A'] > maxCount) {
            maxCount = charCounts[tasks[i] - 'A'];
            maxCountTasks = 1;
        }
    }

    int partitions = maxCount - 1;
    int emptySlots = partitions * (n - maxCountTasks + 1);
    int availableTasks = sizeof(tasks) / sizeof(tasks[0]) - maxCount * maxCountTasks;
    int idleSlots = (emptySlots - availableTasks) > 0 ? (emptySlots - availableTasks) : 0;

    return sizeof(tasks) / sizeof(tasks[0]) + idleSlots;
}

int main() {
    char tasks[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    int minIntervals = leastInterval(tasks, n);
    printf("Least number of intervals: %d\n", minIntervals);

    return 0;
}
