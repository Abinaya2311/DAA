#include <iostream>

using namespace std;

// Structure to hold both max and min values
struct MaxMin {
    int max_val;
    int min_val;
};

// Function to find maximum and minimum values in a list using Divide and Conquer
MaxMin findMaxMin(int arr[], int low, int high) {
    MaxMin result, left, right;

    // Base case: If there's only one element
    if (low == high) {
        result.max_val = arr[low];
        result.min_val = arr[low];
        return result;
    }

    // Base case: If there are two elements
    if (high == low + 1) {
        result.max_val = max(arr[low], arr[high]);
        result.min_val = min(arr[low], arr[high]);
        return result;
    }

    int mid = (low + high) / 2;

    // Divide the array into two halves and find max and min in each half
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

    // Compare max and min values from left and right halves
    result.max_val = max(left.max_val, right.max_val);
    result.min_val = min(left.min_val, right.min_val);

    return result;
}

int main() {
    int arr[] = {7, 3, 10, 5, 2, 8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MaxMin result = findMaxMin(arr, 0, arr_size - 1);

    cout << "Maximum value in the list: " << result.max_val << endl;
    cout << "Minimum value in the list: " << result.min_val << endl;

    return 0;
}
