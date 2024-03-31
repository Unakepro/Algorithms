#include <iostream>
#include "heapsort.hpp"

int main() {
	int arr[] = {2, 15, 37, 141, 26, 13, 174};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr, size);

	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
		


	return 0;
}

