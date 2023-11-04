#include <iostream>
#include <algorithm>
#include <cstring>

constexpr int decimal = 10;


void counting_sort(int* arr, int size, int* output, int* pos, int pos_size, int k) {

	memset(pos, 0, pos_size*sizeof(pos[0]));		

	for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
		pos[arr[incr_elem]/k%10] += 1;
	}
	
	for(int i=0;i<10;++i) {
		std::cout << pos[i] << ' ';
	}
	
	std::cout << '\n';

	for(int add_elem = 0; add_elem < pos_size; ++add_elem) {
		pos[add_elem] += pos[add_elem-1];
	}

	for(int i = size-1; i >= 0; --i) {		

		--pos[arr[i]/k%10];
		output[pos[arr[i]/k%10]] = arr[i]; 

	}	
}



int main() {
	int* arr = new int[8]; 	

	arr[0] = 250;
	arr[1] = 700;
	arr[2] = 20;
	arr[3] = 23;
	arr[4] = 10;
	arr[5] = 21;
	arr[6] = 29;
	arr[7] = 2;


	int size = 8;

	int* output = new int[size];	
	int* pos = new int[decimal];


		
	int max_elem = *(std::max_element(arr, arr+size));
	int div = 1;
	
	while(max_elem != 0) {	
		counting_sort(arr, size, output, pos, decimal, div);
	
		std::swap(arr, output);
		

		div *= 10;
		max_elem /= 10;	
	}

	for(int i = 0;i < size; ++i) {
		std::cout << arr[i] << ' ';	
	}

	
	delete [] arr;
	delete [] output;
	delete [] pos;
	

	return 0;
}
