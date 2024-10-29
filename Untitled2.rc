#include <iostream>
#include <string>

using namespace std;

bool containsTwice(string str, char ch) {
    int count = 0;

    // Loop through each character in the string
    for (char c : str) {
        // If the character matches the given character, increment the count
        if (c == ch) {
            count++;
        }
        // If the count reaches 2, return true
        if (count == 2) {
            return true;
        }
    }

    // If the count is less than 2, return false
    return false;
}

int main() {
    cout << boolalpha; // Print boolean values as 'true' or 'false'

    // Test cases
    cout << containsTwice("hello", 'l') << endl;  // true
    cout << containsTwice("hello", 'h') << endl;  // false
    cout << containsTwice("hello", 'o') << endl;  // false

    return 0;
}
