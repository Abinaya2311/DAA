#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate binomial coefficient C(n, k)
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print Pascal's triangle
void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        // Print spaces to align triangle properly
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << " ";
        }
        
        // Calculate and print values for the current row
        for (int j = 0; j <= i; j++) {
            cout << binomialCoefficient(i, j) << " ";
        }
        
        cout << endl;
    }
}

int main() {
    int numRows;

    cout << "Enter the number of rows for Pascal's triangle: ";
    cin >> numRows;

    printPascalTriangle(numRows);

    return 0;
}
