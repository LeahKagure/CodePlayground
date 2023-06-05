// Given a set of jobs with their deadlines and their profits, find the maximum profit that can be earned
// by scheduling the jobs without missing any deadlines

#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void jobSequencing(struct Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    char sequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        sequence[i] = ' ';
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (sequence[j] == ' ') {
                sequence[j] = jobs[i].id;
                break;
            }
        }
    }

    int totalProfit = 0;
    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (sequence[i] != ' ') {
            printf("%c ", sequence[i]);
            totalProfit += jobs[i].profit;
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    struct Job jobs[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    printf("\n");
    return 0;
}
