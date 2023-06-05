// Given a set of coin denominations and a target amount, find the minimum number of coins needed
// to make the target amount

#include <stdio.h>

int minCoins(int coins[], int n, int target) {
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (target >= coins[i]) {
            target -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int target = 34;
    int result = minCoins(coins, n, target);
    printf("Minimum number of coins required: %d\n", result);
    printf("\n");
    return 0;
}
