# Given a set of items with their weights and values, fill a knapsack of limited capacity with items
# to maximize the total value, considering fractions of items

def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    value_per_weight = [v / w for v, w in zip(values, weights)]

    sorted_indices = sorted(range(n), key=lambda i: -value_per_weight[i])

    current_weight = 0
    final_value = 0

    for i in sorted_indices:
        if current_weight + weights[i] <= capacity:
            current_weight += weights[i]
            final_value += values[i]
        else:
            remaining_capacity = capacity - current_weight
            final_value += value_per_weight[i] * remaining_capacity
            break

    print("Maximum value in knapsack:", final_value)

weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
fractional_knapsack(weights, values, capacity)
