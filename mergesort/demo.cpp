#include "mergesort.hpp" 

int main() {
	int arr[] = {-50, 100, 20, -5, 0, 5, 10};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	mergesort(arr, arr_size);

	for(int i = 0; i < arr_size; ++i) {
		std::cout << arr[i] << ' ';
	}

}