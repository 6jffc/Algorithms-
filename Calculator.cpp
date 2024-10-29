#include <iostream>
#include <string>
using namespace std;

int Operation(int number1, int number2, string operation) {
    if (operation == "add" || operation == "Add" || operation == "ADD") {
        return number1 + number2;
    } 
    else if (operation == "multiply" || operation == "Multiply" || operation == "MULTIPLY") {
        return number1 * number2;
    } 
    else if (operation == "subtract" || operation == "Subtract" || operation == "SUBTRACT") {
        return number1 - number2;
    } 
    else {
        cout << "Unsupported operation";
        return 0; // Tr�?ng h?p m?c �?nh khi kh�ng ph� h?p v?i c�c �i?u ki?n tr�n
    }
}

int main() {
    int number1, number2;
    string operation;

    cout << "Enter number 1: ";
    cin >> number1;

    cout << "Enter number 2: ";
    cin >> number2;

    cout << "Enter operation (add, multiply, subtract): ";
    cin >> operation;

    int result = Operation(number1, number2, operation);
    cout << "Result: " << result << endl;

    return 0;
}

