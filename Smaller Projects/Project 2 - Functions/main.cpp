#include <iostream>
#include <cassert>

int main();
void pattern(unsigned int n);

// this function take in n and output a pattern of * base on the n value
void pattern(unsigned int n) {
    for (int r = 0; r <= n; r++) {
        for (int c = 0; c < n*2+1; c++) {
            if (c < r || c+r >= n*2+1) {
                std::cout << " ";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    for (int r = n-1; r >= 0; r--) {
        for (int c = 0; c < n*2+1; c++) {
            if (c < r || c+r >= n*2+1) {
                std::cout << " ";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

int main () {
    // first function
    int n{0};
    std::cin >> n;
    pattern(n);
    
    return 0;
}