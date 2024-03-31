#include "insertion_sort.hpp"


int main() {
	int arr[] = {20, -50, 20, 0, 5, 10, 100};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	insertion_sort(arr, arr_size);

	for(int i = 0; i < arr_size; ++i) {
		std::cout << arr[i] << ' ';
	}

}