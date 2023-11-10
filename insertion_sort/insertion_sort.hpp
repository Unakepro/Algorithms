#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <iostream>
#include <algorithm>

void insertion_sort(int *arr, int len) {
	for (int i = 1 ; i < len ; i++) {
		int val = arr[i];
		int cur = i;
		while ((cur > 0) && arr[cur - 1] > val ) {
				arr[cur] = arr[cur - 1];
				cur--;
		}
		arr[cur] = val;
	}
}



#endif
