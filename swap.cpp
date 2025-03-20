#include <iostream>
#include <utility> // for std::swap

int main() {
    int a, b;
    std::cout << "a = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    // std::swap từ thư viện <utility> để hoán đổi hai biến, thay vì tự định nghĩa hàm swap.
    std::swap(a, b);
    std::cout << a << ", " << b << std::endl;

    return 0;
}
