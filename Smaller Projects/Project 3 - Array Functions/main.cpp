#include <iostream>
#include <cassert>

int main();
double *geometric(double a, double ratio, std::size_t cap);
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates(int array[], std::size_t capacity);
void deallocate(double *&ptr, bool is_array, std::size_t capacity);

/**
 * @param (the first term of the geometric sequence) a
 * @param (the ratio between terms of the geometric sequence) ratio
 * @param (the size of the geometric sequence) cap
 * @return return the address of this dynamically allocated array contains a geometric sequence
 */
double *geometric(double a, double ratio, std::size_t cap) {
    double *control_geometric{new double[cap]};
    control_geometric[0] = a;
    for (std::size_t i = 1; i < cap; ++i) {
        control_geometric[i] = control_geometric[i-1]*ratio;
    }

    return control_geometric;
}

/**
 * @param (the first array of the correlation) array0
 * @param (the size of the first array) cap0
 * @param (the second array of the correlation) array1
 * @param (the size of the second array) cap1
 * @return return the address of this dynamically allocated array contains the correlation between array0 and array 1
 */
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert(cap0 + cap1 >= 1);
    double *control_correlation{new double[cap1 + cap0 - 1]};
    for (std::size_t i{0}; i < cap0; ++i) {
        for (std::size_t j{0}; j < cap1; ++j) {
            control_correlation[i+j] = array0[i]*array1[j];
        }
    }

    return control_correlation;
}

/**
 * 
 */
std::size_t shift_duplicates(int array[], std::size_t capacity) {
    std::size_t unique_count{0};
    std::size_t dup_count{0};
    while (unique_count+dup_count < capacity) {
        bool is_dup{false};
        for (std::size_t i{0}; i < unique_count; i++) {
            if (array[i] == array[unique_count]) {
                for (std::size_t c{unique_count+1}; c < capacity; ++c) {
                    int temp = array[c-1];
                    array[c-1] = array[c];
                    array[c] = temp;
                }
                ++dup_count;
                is_dup = true;
                break;
            }
        }
        if (!is_dup) {
            ++unique_count;
        }
    }

    return unique_count;
}

/**
 * 
 */
void deallocate(double* &ptr, bool is_array, std::size_t capacity = 0) {
    std::cout << "????" << std::endl;
    if (is_array) {
        for (int i{0}; i < capacity; ++i) {
            ptr[i] = 0;
        }
        std::cout << "::" << std::endl;
        // delete[] ptr;
    }
    else {
        ptr = 0;
        // delete ptr;
    }
    std::cout << ":" << std::endl;
    ptr = nullptr;
}

int main() {
    // first function
    double *geomatric_seq{geometric(2, 2, 10)};
    std::cout << geomatric_seq << std::endl;
    // for (int i = 0; i < 10; ++i) {
    //     std::cout << geomatric_seq[i] << std::endl;
    // }

    // second function
    double array0[1]{};
    double *correlations{cross_correlation(array0, 1, array0, 1)};
    std::cout << correlations << std::endl;

    // third function
    int testing[10]{5, 4, 2, 2, 2, 4, 5, 1, 4, 3};
    std::size_t count = shift_duplicates(testing, 10);
    for (int i{0}; i < 10; ++i) {
        std::cout << i << "." << testing[i] << std::endl;
    }
    std::cout << count << std::endl;

    // fourth function
    double test[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    double* tests = test;
    deallocate(tests, true, 10);
    std::cout << "?" << std::endl;

    return 0;
}