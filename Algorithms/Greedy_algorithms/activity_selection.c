// Given a list of activities with their start and finish times, select the maximum of
// non-overlapping activities that can be performed

#include <stdio.h>

void printMaxActivities(int start[], int finish[], int n) {
    int i, j;
    printf("Selected activities: ");
    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    printMaxActivities(start, finish, n);
    printf("\n");
    return 0;
}
