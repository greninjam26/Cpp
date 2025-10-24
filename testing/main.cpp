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
    std::cout << (2147483647 << 1) << std::endl;
    std::cout << (-2 >> 2) << std::endl;

    // just declaring and output
    double hii;
    // hii /= 10;
    std::cout << hii << std::endl;

    // checking the size of each data type
    std::cout << "char:       " << sizeof( char )      << std::endl;
    std::cout << "short:      " << sizeof( short )     << std::endl;
    std::cout << "int:        " << sizeof( int )       << std::endl;
    std::cout << "long:       " << sizeof( long )      << std::endl;
    std::cout << "long long:  " << sizeof( long long ) << std::endl;

    // array size
    int array_0[1];  //   4 bytes = 0x04 bytes
    int array_00[5];  //  20 bytes = 0x14 bytes
    int array_1[12]; //  48 bytes = 0x30 bytes
    int array_2[20]; //  80 bytes = 0x50 bytes
    int array_3[52]; // 208 bytes = 0xd0 bytes
    int array_4[52]; // 208 bytes = 0xd0 bytes
    int array_5[4];  //  16 bytes = 0x10 bytes

    std::cout << array_0 << std::endl;
    std::cout << array_00 << std::endl;
    std::cout << array_1 << std::endl;
    std::cout << array_2 << std::endl;
    std::cout << array_3 << std::endl;
    std::cout << array_4 << std::endl;
    std::cout << array_5 << std::endl;

    // c-styled string
    char strings[3]{'G', 'o', '\0'};
    // without the \0 it just keep going
    char stringss[3]{'G', 'o', 'o'};
    
    std::cout << "string: " << strings << std::endl;
    std::cout << "strings: " << stringss << std::endl;

    // testing out mod(%)
    std::cout << "??" << (-6%16) << std::endl;
    int a{-6};
    int b{16};
    int r = a%b;
    std::cout << "?" << r << std::endl;

    // testing output
    std::cout << "\\" << std::endl;

    char testingcs = 'e';
    char cstrings[1];
    cstrings[0] = 'h';
    std::cout << "strings: " << cstrings << std::endl;


    // meaning leaving without an error
    return 0;
}