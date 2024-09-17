#include <iostream>
#include <cstdlib>  // For abs()

int gcd(int a, int b) {
    return b == 0 ? std::abs(a) : gcd(b, a % b);
}

int lcm(int a, int b) {
    return std::abs(a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << std::endl;
    return 0;
}