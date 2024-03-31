#include <iostream>
#include "hybridsort.hpp"

int main() {
	int arr[] = {0, 1, 1, 2, 3, 5, 7, 9};
	int size = sizeof(arr)/sizeof(arr[0]);


	hybridsort(arr, size);

	for(int count = 0; count < size; ++count) {
		std::cout << arr[count] << ' ';
	}

}
