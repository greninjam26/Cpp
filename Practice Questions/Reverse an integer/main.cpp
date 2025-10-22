#include <iostream>

int main();
int reverse(int n);

int reverse(int n) {
    int int_digit[15]{};
    bool is_negative{false};
    if (n < 0) {
        n *= -1;
        is_negative = true;
    }
    int inversed{0};
    if (n == 0) {
        return 0;
    }
    int counter{0};
    while (n > 0)
    {
        // std::cout << n%10 << std::endl;
        int_digit[counter] = n%10;
        n /= 10;
        counter++;
    }
    for (int i = 0; i < counter; i++) {
        inversed += int_digit[i];
        inversed *= 10;
        // std::cout << "?" << inversed << std::endl;
    }
    inversed /= 10;
    if (is_negative) {
        inversed *= -1;
    }
    return inversed;
    
}

int main() {
    int n{0};
    std::cin >> n;
    std::cout << reverse(n) << std::endl;
    return 0;
}