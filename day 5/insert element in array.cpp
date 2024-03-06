#include <iostream>
using namespace std;

int main() {
    int array[] = {2, 3, 5, 4, 1, 7}; // Predefined array
    int length = sizeof(array) / sizeof(array[0]); // Predefined length
    int position;
    int newValue;
    int i;

    // Insertion
    cout << "Enter the position for insertion: ";
    cin >> position;

    cout << "Enter the new value for insertion: ";
    cin >> newValue;

    if (position >= 0 && position <= length) {
        for (i = length; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = newValue;
        length++;
    }

    // Printing the array after insertion
    cout << "Array after insertion: ";
    for (i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
