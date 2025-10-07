// run code in terminal: 
// compiler -std=c++[version] fileName -o Name
// ./Name
// clang++ -std=c++17 test.cpp -o test
// ./test
// compile and run
// clang++ -std=c++17 test.cpp -o test.exe ; ./test.exe
#include <iostream>

// function declarations
int main();

// function definitions
int main() {
    // std: standard
    std::cout << "???????????....??." << std::endl;

    // testing for bitwise operations
    unsigned int n{11};
    unsigned int m{10};
    // 0b with this prefix, it means binary number
    // 0x this is hexdecimal
    // &, |, ^ always return a decimal number, even if the input is binary
    unsigned int x = n & m;
    std::cout << "X: " << x << std::endl;
    std::cout << "x: " << (0b10 & 0b111) << std::endl;
    // add a zero to the end of the binary number
    std::cout << "left: " << (0b110 << 1) << std::endl;
    // remove the last digit of the binary number
    std::cout << "right: " << (0b110 >> 1) << std::endl;

    // swapping bytes
    std::cout << (2 << 8) << std::endl;

    // meaning leaving without an error
    return 0;
}