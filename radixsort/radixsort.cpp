#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

constexpr int decimal = 10;

void counting_sort(int* arr, int size, int* output, int* pos, int pos_size, int k) {

	memset(pos, 0, pos_size*sizeof(pos[0]));		

	for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
		pos[arr[incr_elem]/k%10] += 1;
	}
	
	for(int add_elem = 0; add_elem < pos_size; ++add_elem) {
		pos[add_elem] += pos[add_elem-1];
	}

	for(int i = size-1; i >= 0; --i) {		

		--pos[arr[i]/k%10];
		output[pos[arr[i]/k%10]] = arr[i]; 

	}	
}


void counting_negative(int* arr, int size, int* output, int* pos, int pos_size, int k=1) {

	memset(pos, 0, pos_size*sizeof(pos[0]));		

	for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
		pos[arr[incr_elem]/k%10] += 1;
	}
	
	for(int add_elem = 0; add_elem < pos_size; ++add_elem) {
		pos[add_elem] += pos[add_elem-1];
	}

	for(int i = size-1; i >= 0; --i) {		

		--pos[arr[i]/k%10];
		output[pos[arr[i]/k%10]] = arr[i]; 

	}	
}


void radixsort(int* arr, int size) {
	
	int* output = new int[size];	
	int* pos = new int[decimal];

	int max_elem = *(std::max_element(arr, arr+size));

	int div = 1;
	while(max_elem > 0) {	
		counting_sort(arr, size, output, pos, decimal, div);
	
		std::swap(arr, output);
		

		div *= 10;
		max_elem /= 10;	
	}
	
	delete [] output;
	delete [] pos;	
}




int main() {
	int arr[] = {1, 250, 1000, 9, 1001, 120, 9, 0, 1}; 	

	int size = sizeof(arr)/sizeof(arr[0]);

	radixsort(arr, size);
	
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
 


	return 0;
}
