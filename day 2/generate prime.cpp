#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n, int i = 2) {
    if (n <= 2) return (n == 2) ? true : false;
    if (n % i == 0) return false;
    if (i * i > n) return true;
    return isPrime(n, i + 1);
}

void generatePrimes(int n) {
    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;
    generatePrimes(limit);
    return 0;
}
