#include <iostream>
#include <string>
using namespace std;

void copyString(const string& src, string& dest, int index = 0) {
    if (index >= src.length()) {
        return;
    }
    
    dest.push_back(src[index]);
    copyString(src, dest, index + 1);
}

int main() {
    string source = "Hello, World!";
    string destination;
    copyString(source, destination);
    cout << "Copied string: " << destination << endl;
    return 0;
}
