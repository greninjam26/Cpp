#include <iostream>

int main();

int main() {
    unsigned int m = (1 << 8);
    std::cout << m << std::endl;
    m -= 1;
    std::cout << m << std::endl;
    std::cout << (m << 4) << std::endl;
    m ^= (m << 4);
    std::cout << m << std::endl;
}