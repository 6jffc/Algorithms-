#include <iostream>
#include <string>

void PrintOneDigit(int d) {
    switch (d) {
        case 0: std::cout << "zero"; break;
        case 1: std::cout << "one"; break;
        case 2: std::cout << "two"; break;
        case 3: std::cout << "three"; break;
        case 4: std::cout << "four"; break;
        case 5: std::cout << "five"; break;
        case 6: std::cout << "six"; break;
        case 7: std::cout << "seven"; break;
        case 8: std::cout << "eight"; break;
        case 9: std::cout << "nine"; break;
        default: std::cerr << "Illegal call to PrintOneDigit"; break;
    }
}

void PrintTeen(int n) {
    switch (n) {
        case 10: std::cout << "ten"; break;
        case 11: std::cout << "eleven"; break;
        case 12: std::cout << "twelve"; break;
        case 13: std::cout << "thirteen"; break;
        case 14: std::cout << "fourteen"; break;
        case 15: std::cout << "fifteen"; break;
        case 16: std::cout << "sixteen"; break;
        case 17: std::cout << "seventeen"; break;
        case 18: std::cout << "eighteen"; break;
        case 19: std::cout << "nineteen"; break;
        default: std::cerr << "Illegal call to PrintTeen"; break;
    }
}

void PrintTens(int n) {
    switch (n) {
        case 2: std::cout << "twenty"; break;
        case 3: std::cout << "thirty"; break;
        case 4: std::cout << "forty"; break;
        case 5: std::cout << "fifty"; break;
        case 6: std::cout << "sixty"; break;
        case 7: std::cout << "seventy"; break;
        case 8: std::cout << "eighty"; break;
        case 9: std::cout << "ninety"; break;
        default: std::cerr << "Illegal call to PrintTens"; break;
    }
}

void PrintHundreds(int n) {
    if (n >= 100) {
        PrintOneDigit(n / 100);
        std::cout << " hundred ";
        n %= 100;
    }
    if (n >= 20) {
        PrintTens(n / 10);
        if (n % 10 != 0) {
            std::cout << "-";
            PrintOneDigit(n % 10);
        }
    } else if (n >= 10) {
        PrintTeen(n);
    } else if (n > 0) {
        PrintOneDigit(n);
    }
}

void PrintNumber(int n) {
    if (n == 0) {
        std::cout << "zero";
    } else {
        if (n < 0) {
            std::cout << "minus ";
            n = -n;
        }
        
        if (n >= 1000) {
            PrintHundreds(n / 1000);
            std::cout << " thousand ";
            n %= 1000;
        }
        
        PrintHundreds(n);
    }
}

int main() {
    std::cout << "Enter numbers in figures; use a negative value to stop." << std::endl;
    while (true) {
        int number;
        std::cout << "Number: ";
        std::cin >> number;

        if (number < 0) {
            break;
        }

        PrintNumber(number);
        std::cout << std::endl;
    }

    return 0;
}

