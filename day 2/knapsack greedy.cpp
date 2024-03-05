#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compareItems(const Item& a, const Item& b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2; // Sort in non-decreasing order of value/weight ratio
}

// Function to solve the Knapsack problem using a greedy approach
int knapsackGreedy(Item items[], int n, int capacity) {
    // Sort items based on their value per unit weight
    sort(items, items + n, compareItems);

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            // If adding the entire item does not exceed the capacity, add it
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, add a fraction of the item to fill the remaining capacity
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}}; // Sample items: value, weight
    int n = sizeof(items) / sizeof(items[0]); // Number of items
    int capacity = 50; // Knapsack capacity

    int maxValue = knapsackGreedy(items, n, capacity);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}

