#include <iostream>

// Function to round a floating-point number x to the nearest integer
int Round(float x) {
    if (x >= 0)
        return int(x + 0.5);  // Round positive numbers using the formula x + 0.5
    else
        return int(x - 0.5);  // Round negative numbers using the formula x - 0.5
}

int main() {
    float number;
    std::cout << "Enter a floating-point number: ";
    std::cin >> number;

    int rounded = Round(number);

    std::cout << "Rounded value: " << rounded << std::endl;

    return 0;
}

