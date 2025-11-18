#include "p_4_header.hpp"
#include <iostream>

std::size_t length( char const *a ){
    std::size_t count{0};
    std::size_t i{0};
    while (a[i] != '\0') {
        ++count;
        ++i;
    }
    return count;
}
int compare( char const *str1, char const *str2 ){
    int i{0};
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        }
        else if (str1[i] > str2[i]) {
            return 1;
        }
        ++i;
    }
    return 0;
}
void assign( char *str1, char const *str2 ){
    int i{0};
    while (str1[i] != '\0' || str2[i] != '\0') {
        str1[i] = str2[i];
        ++i;
    }
}
unsigned int distance( char const *str1, char const *str2 ){
    // std::cout << str1 << "????" << str2 << std::endl;
    if (str1[0] == '\0') {
        return length(str2);
    }
    if (str2[0] == '\0') {
        return length(str1);
    }
    if (str1[0] == str2[0]) {
        return distance(str1+1, str2+1);
    }
    return std::min(std::min(distance(str1, str2+1), distance(str1+1, str2)), distance(str1+1, str2+1))+1;
}
std::size_t is_sorted( char *array[], std::size_t capacity ){
    for (std::size_t i{1}; i < capacity; ++i) {
        if(compare(array[i], array[i-1]) == -1) {
            return i;
        }
    }
    return capacity;
}
void insert( char *array[], std::size_t capacity ){
    // std::cout << "?" << std::endl;
    for (std::size_t i{capacity-1}; i > 0; --i) {
        if (compare(array[i], array[i-1]) == -1) {
            // std::cout << "??" << std::endl;
            char temp[50]{""};
            assign(temp, array[i-1]);
            assign(array[i-1], array[i]);
            assign(array[i], temp);
            // std::cout << "???" << std::endl;
        }
    }
}
void insertion_sort( char *array[], std::size_t capacity ){}
std::size_t remove_duplicates( char *array[], std::size_t capacity ){
    return 0;
}
std::size_t find( char *array[], std::size_t capacity, char const *str ){
    return 0;
}

void free_word_array( char** word_array ){}