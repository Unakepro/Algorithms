#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <iostream>
#include <algorithm>

void insertion_sort(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		for(int j = i-1; j >= 0; --j) {
			if(arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
			}
			else {
				break;
			}
		}	
	}
}




#endif
