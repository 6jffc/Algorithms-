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
        return 0; // Trý?ng h?p m?c ð?nh khi không phù h?p v?i các ði?u ki?n trên
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
/*
#include <iostream>
#include <string>
#include <unordered_map> //Thư viện này cung cấp cấu trúc dữ liệu bảng băm
#include <functional> //Thư viện này cho phép sử dụng các đối tượng hàm std::function.

int main(){
    int number1, number2;
    std::string oparation;

    std::cout << "Enter number 1: ";
    std::cin >> number1;

    std::cout << "Enter number 2: ";
    std::cin >> number2;

    std::cout << "Enter operation (add, multiply, subtract): ";
    std::cin >> operation;

    std::unordered_map<std::string, std::function<int(int, int)>> operations = {
        {"add", [](int a, int b) { return a + b; }},
        {"multiply", [](int a, int b) { return a * b; }},
        {"subtract", [](int a, int b) { return a - b; }}
    };
    auto it = operations.find(operation);
    if (it != operations.end()) {
        std::cout << "Result: " << it->second(number1, number2) << std::endl;
    } else {
        std::cout << "Unsupported operation" << std::endl;
    }

    return 0;
    
}*/
