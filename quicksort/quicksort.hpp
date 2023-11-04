#ifndef QUICKSORT
#define QUICKSORT

#include <iostream>
#include <vector>

void quicksort(int* arr, int size) {

	if(size > 1) {

		int l = 1;
		int r = size-1;
	
		std::swap(arr[0], arr[size/2]);
		int start_elem = arr[0];	
		
		while(l <= r) {
			if(arr[l] > start_elem) {
				if(arr[r] < start_elem) {
					std::swap(arr[l], arr[r]);
					++l;
				}
				else {
						--r;
				}
			}
			else {
				++l;
			}
		}
		std::swap(arr[r], arr[0]);

		quicksort(arr, r);
		quicksort(arr+r+1, size-r-1);
	}
}


#endif
