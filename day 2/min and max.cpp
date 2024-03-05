#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int arr[] = {5, 3, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* minptr = min_element(arr, arr + size);
    int min = *minptr;
    int* maxptr = max_element(arr, arr + size);
    int max = *maxptr;

    cout << "The minimum element in the array is: " << min << endl;
    cout << "The maximum element in the array is: " << max << endl;
    return 0;
}

