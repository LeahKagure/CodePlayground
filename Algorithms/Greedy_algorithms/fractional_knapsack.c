// Given a set of items with their weights and values, fill a knapsack of limited capacity with items
// to maximize the total value, considering fractions of items

#include <stdio.h>

void fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double) values[i] / weights[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (valuePerWeight[j] > valuePerWeight[maxIndex]) {
                maxIndex = j;
            }
        }
        double temp = valuePerWeight[i];
        valuePerWeight[i] = valuePerWeight[maxIndex];
        valuePerWeight[maxIndex] = temp;

        int temp2 = weights[i];
        weights[i] = weights[maxIndex];
        weights[maxIndex] = temp2;

        temp2 = values[i];
        values[i] = values[maxIndex];
        values[maxIndex] = temp2;
    }

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            finalValue += values[i];
        } else {
            int remainingCapacity = capacity - currentWeight;
            finalValue += valuePerWeight[i] * remainingCapacity;
            break;
        }
    }

    printf("Maximum value in knapsack: %.2lf\n", finalValue);
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);
    fractionalKnapsack(weights, values, n, capacity);
    printf("\n");
    return 0;
}
