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
// 1234
// 1, 2. 2134
// 1, 3. 3214
// 1, 4. 4231
// 2, 3. 1324
// 2, 4. 1432
// 3, 4. 1243
// 4289396650
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    if (b0 != b1) {
        unsigned int b0byte = ((n & (255 << b0 * 8)) >> (b0 * 8)) << (b1 * 8);
        unsigned int b1byte = ((n & (255 << b1 * 8)) >> (b1 * 8)) << (b0 * 8);
        std::cout << b0byte << std::endl;
        std::cout << b1byte << std::endl;
        unsigned int clearbytes{0};
        for (int i = 0; i < 4; i++) {
            clearbytes <<= 8;
            std::cout << "?" << clearbytes << std::endl;
            if (i != b0 && i != b1) {
                std::cout << i << " " << b0 << " " << b1 << std::endl;
                clearbytes |= 255;
            }
            std::cout << "??" << clearbytes << std::endl;
        }
        std::cout << "clear: " << clearbytes << std::endl;
        n &= clearbytes;
        std::cout << "n: " << n << std::endl;
        n |= b0byte;
        n |= b1byte;
    }
    return n;
}

int main () {
    // // first function
    // unsigned int patterns_input{0};
    // std::cout << "Please enter a number to generate a pattern: " << std::endl;
    // std::cin >> patterns_input;
    // pattern(patterns_input);

    // // second function
    // unsigned int logn{0};
    // unsigned int result{0};
    // std::cout << "Please enter a number to be calculated by log: " << std::endl;
    // std::cin >> logn;
    // result = log10(logn);
    // std::cout << "result: " << result << std::endl;

    // // third function
    // unsigned int initial_number{0};
    // unsigned int bit_check{0};
    // unsigned int bit_count{0};
    // std::cout << "Please enter the number to be checked: ";
    // std::cin >> initial_number;
    // std::cout << "Please enter the bit you want to check: ";
    // std::cin >> bit_check;
    // bit_count = count(initial_number, bit_check);
    // std::cout << bit_count << std::endl;

    // fourth function
    unsigned int initial_bytes{0};
    unsigned int b0{0};
    unsigned int b1{0};
    std::cout << "Please enter the original bytes: ";
    std::cin >> initial_bytes;
    std::cout << "Please enter the location of the first byte: ";
    std::cin >> b0;
    std::cout << "Please enter the location of the second byte: ";
    std::cin >> b1;
    unsigned int swapped_bytes{0};
    swapped_bytes = swap_bytes(initial_bytes, b0, b1);
    std::cout << "result: " << swapped_bytes << std::endl;
    // std::cout << ((swapped_bytes << 8) | 255) << std:: endl;
    
    return 0;
}