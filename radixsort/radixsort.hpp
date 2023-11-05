#ifndef RADIXSORT
#define RADIXSORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

constexpr int decimal = 10;

void counting_sort(int* arr, int size, int* output, int k) {

    int pos[decimal] = {};

    for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
        pos[arr[incr_elem]/k%10] += 1;
    }

    for(int add_elem = 1; add_elem < decimal; ++add_elem) {
        pos[add_elem] += pos[add_elem-1];
    }

    for(int i = size-1; i >= 0; --i) {
        pos[arr[i]/k%10] -= 1;
        output[pos[arr[i]/k%10]] = arr[i];
    }

    for(int count = 0; count < size; ++count) {
        arr[count] = output[count];
    }

}



void radixsort(int* arr, int size) {

    int* output = new int[size];


    int least_elem = *(std::min_element(arr, arr+size));
    int max_elem = *(std::max_element(arr, arr+size));


    if(least_elem + max_elem + 1 >= INT_MAX) {
        throw std::runtime_error("Does not work with this range of values");
    }

    for(int i = 0; i < size; ++i) {
        arr[i] += abs(least_elem)+1;
    }

    max_elem += abs(least_elem)+1;

    int div = 1;
    while(max_elem > 0) {
        counting_sort(arr, size, output, div);

        div *= 10;
        max_elem /= 10;
    }

    for(int i = 0; i < size; ++i) {
        arr[i] -= abs(least_elem)+1;
    }

    delete [] output;
}



#endif
