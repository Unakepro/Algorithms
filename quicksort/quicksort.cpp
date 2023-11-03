#include <iostream>
#include <vector>


void partition(int* arr, int size) {
	int l = 1;
	int r = size-1;
	int start_elem = arr[0];	
	
	while(l < r) {
		if(arr[l] > start_elem) {
			if(arr[r] < start_elem) {
				std::swap(arr[l], arr[r]);
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
}


void quicksort(int* arr, int size) {
	int half_size = size/2; 
	if(size > 2) {
		partition(arr, size);
		quicksort(arr, half_size);
		quicksort(arr+half_size, size-half_size);
	}
}



int main() {
	int arr[] = {10, 125, 17, 3, 14, 126, 2, 9, 21, 22, 3};
	int size = sizeof(arr)/sizeof(arr[0]);

	partition(arr, size);

	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
}
