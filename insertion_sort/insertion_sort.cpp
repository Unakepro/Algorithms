#include <iostream>
#include <algorithm>

int main() {

	int arr[] = {5, 7, 2, 1, 8, 12, 7};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < size; ++i) {
		for(int j = i-1; j >= 0; --j) {
			if(arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
			}
			else {
				break;
			}
		}	
	}


	for(int arr_s = 0; arr_s < size; ++arr_s) {
		std::cout << arr[arr_s];
	}

	return 0;
}
