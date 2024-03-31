#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <vector>

void bubble_sort(std::vector<int>& arr) {
    for(int i =  0; i < arr.size(); ++i) {
        for(int j = 0; j < arr.size()-i-1; ++j) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        } 
    }
}

#endif