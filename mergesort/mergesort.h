#ifndef MERGESORT
#define MERGESORT


#include <iostream>
#include <cassert>
#include <algorithm>




void merge(int* left, int size_l, const int* right, int size_r) {
	int l = 0;
    int r = 0;
    int i = 0;


    int* tmp = new int[size_l+size_r];
    while(l < size_l && r < size_r) {
		
		assert(l < size_l);
    	assert(r < size_r);    
	
		if(left[l] <= right[r]) {
            tmp[i] = left[l];
            ++l;
        }
        else {
            tmp[i] =  right[r];
            ++r;
        }
        ++i;
    }


    for(;l < size_l; ++l) {
        tmp[i] = left[l];
        ++i;
    }
    for(;r < size_r; ++r) {
        tmp[i] = right[r];
        ++i;
    }

	assert(std::is_sorted(tmp, tmp+size_l+size_r));
    for(int j=0;j<size_r+size_l;++j) {
        left[j] = tmp[j];
    }
    delete [] tmp;
}





void mergesort(int* arr, int size) {
    if(size > 1) {
        mergesort(arr, size-size/2);
        mergesort(arr+(size-size/2), size/2);
	
		assert(std::is_sorted(arr, arr+(size-size/2)));
		assert(std::is_sorted(arr+(size-size/2), arr+size));	

        merge(arr, size-size/2, arr+(size-size/2), size/2);
    }
}


	

#endif
