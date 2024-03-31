#include "radixsort.hpp"


int main() {
	int arr[] = {-50000, -20, 100, -3, 10000, 20, 22, 13};

	int size = sizeof(arr)/sizeof(arr[0]);

	radixsort(arr, size);
	
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}


	return 0;
}
