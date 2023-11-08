#include <iostream>
#include "quicksort.hpp"

int main() {
	int arr[] = {1, 2,  9, 5, 22, 3};
	int size = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, size);

	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
}
