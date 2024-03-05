#include <iostream>
using namespace std;

void displaySubset(int subset[], int size) {
    cout << "Subset: ";
    for (int i = 0; i < size; ++i) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void subsetSum(int arr[], int subset[], int size, int index, int subIndex, int targetSum) {
    if (targetSum == 0) {
        displaySubset(subset, subIndex);
        return;
    }
    if (index >= size || targetSum < 0) {
        return;
    }

    subset[subIndex] = arr[index];
    subsetSum(arr, subset, size, index + 1, subIndex + 1, targetSum - arr[index]);
    subsetSum(arr, subset, size, index + 1, subIndex, targetSum);
}

int main() {
    int arr[] = {2, 5, 8, 4, 6};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    int subset[size];

    subsetSum(arr, subset, size, 0, 0, targetSum);

    return 0;
}
