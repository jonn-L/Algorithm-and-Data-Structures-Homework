#include <iostream>

int get_digit(int num, int n) {
    while (n > 1) {
        num /= 10;
        n--;
    }

    return num % 10;
}

int main() {
    std::cout << get_digit(12345, 5) << std::endl;
}