#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i; // Element found, return its index
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 5, 7, 9, 13, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int index = linearSearch(arr, size, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}

