# Given a set of coin denominations and a target amount, find the minimum number of coins needed
# to make the target amount

def min_coins(coins, target):
    count = 0
    for i in range(len(coins) - 1, -1, -1):
        while target >= coins[i]:
            target -= coins[i]
            count += 1
    return count

coins = [1, 5, 10, 25]
target = 34
result = min_coins(coins, target)
print("Minimum number of coins required:", result)
