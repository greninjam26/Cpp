#include <iostream>
#include <cassert>

int main();
void pattern(unsigned int n);
unsigned int log10(unsigned int n);
unsigned int count(unsigned int n, unsigned int bit);
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1);

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

// this function take in a number and a bit(0, 1), then check the number of the bit is showed up in the binary version of the number
unsigned int count(unsigned int n, unsigned int bit) {
    unsigned int counter{0};
    while (n > 0) {
        if (n%2 == bit) {
            counter++;
        }
        n /= 2;
    }
    return counter;
}

// this function will take in a 32 bit number and swap the two byte in indicated
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    if (b0 != b1) {
        
    }
    return n;
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

    // third function
    unsigned int initial_number{0};
    unsigned int bit_check{0};
    unsigned int bit_count{0};
    std::cout << "Please enter the number to be checked: ";
    std::cin >> initial_number;
    std::cout << "Please enter the bit you want to check: ";
    std::cin >> bit_check;
    bit_count = count(initial_number, bit_check);
    std::cout << bit_count << std::endl;

    // fourth function
    unsigned int initial_bytes{0};
    unsigned int b0{0};
    unsigned int b1{0};
    std::cout << "Please enter the original bytes: ";
    std::cin >> initial_bytes;
    std::cout << "Please enter the location of the first byte";
    std::cin >> b0;
    std::cout << "Please enter the location of the second byte";
    std::cin >> b1;
    unsigned int swapped_bytes{0};
    swapped_bytes = swap_bytes(initial_bytes, b0, b1);
    std::cout << "result: " << swapped_bytes << std::endl;
    
    return 0;
}