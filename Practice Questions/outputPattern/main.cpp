#include <iostream>

int main();
void squiggle(unsigned int n);

void squiggle(unsigned int n) {
    if (n == 0) {
        std::cout << " /" << std::endl;
        std::cout << "/" << std::endl;
        return;
    }
    std::cout << "/" << std::endl;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int r = 0; r < i; r++) {
            std::cout << " ";
        }
        std::cout << "\\" << std::endl;
    }
    for (unsigned int i = 0; i < n-1; i++) {
        std::cout << " ";
    }
    std::cout << "/" << std::endl;
}

int main() {
    unsigned int n{0};
    std::cin >> n;
    squiggle(n);
    return 0;
}