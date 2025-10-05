#include <iostream>
#include <cassert>

int main();
void pattern(unsigned int n);
unsigned int log10(unsigned int n);
unsigned int count(unsigned int n, unsigned int bit);

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

// this function take the input n and calculate log10(n)
unsigned int log10(unsigned int n) {
    unsigned int count{0};
    while (n >= 10) {
        n /= 10;
        count++;
    }
    return count;
}

unsigned int count(unsigned int n, unsigned int bit) {
    return 0;
}

int main () {
    // first function
    unsigned int patterns_input{0};
    std::cout << "Please enter a number to generate a pattern: " << std::endl;
    std::cin >> patterns_input;
    pattern(patterns_input);

    // second function
    unsigned int logn{0};
    unsigned int result{0};
    std::cout << "Please enter a number to be calculated by log: " << std::endl;
    std::cin >> logn;
    result = log10(logn);
    std::cout << "result: " << result << std::endl;

    
    
    return 0;
}