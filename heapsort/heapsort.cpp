#include <iostream>
#include <vector>


void fix(int* arr, int size, int index) {
	int l_child = 2*index+1;
	int r_child = 2*index+2;

	if(l_child < size && r_child < size) {
		int max_child = arr[l_child] >= arr[r_child] ? l_child: r_child;

		if(arr[index] < arr[max_child]) {
			std::swap(arr[index], arr[max_child]);
			fix(arr, size, max_child);	
		}
	}
	else if(l_child < size) {
		if(arr[index] < arr[l_child]) {
			std::swap(arr[index], arr[l_child]);
			fix(arr, size, l_child);
		}
	}
}



void make(int* arr, int size) {
	for(int i = size-1 ; i >= 0; --i) {
		fix(arr, size, i);
	}
}



void heapsort(int* arr, int size) {

	make(arr, size);


	while(size != 0) {
			
		std::swap(arr[0], arr[size-1]);
		--size;
		fix(arr, size,  0);
	}
}



int main() {
	int arr[] = {2, 15, 37, 141, 26, 13, 174};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr, size);

	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
		


	return 0;
}

