#include <iostream>
#include <algorithm>
#include <cstring>

constexpr int decimal = 10;


void counting_sort(int* arr, int size, int* tmp, int* count, int count_size, int k) {

	memcpy(tmp, arr, size*sizeof(arr[0]));
	memset(count, 0, count_size*sizeof(count[0]));		

	for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
		count[arr[incr_elem]/k%10] += 1;
	}
	
	for(int add_elem = 0; add_elem < count_size; ++add_elem) {
		count[add_elem] += count[add_elem-1];
	}

	for(int i = size-1; i >= 0; --i) {
		arr[count[tmp[i]/k%10]-1] = tmp[i];
		--count[tmp[i]/k%10]; 
	}
}



int main() {
	int arr[] = {1020, 1250, 3, 14, 250, 700, 20, 23, 10, 21, 29, 1, 2, 2};

	int size = sizeof(arr)/sizeof(arr[0]);

	int* copy_arr = new int[size];	
	int* count = new int[decimal];

		
	int max_elem = *(std::max_element(arr, arr+size));
	int div = 1;
	
	while(max_elem != 0) {	
		counting_sort(arr, size, copy_arr, count, decimal, div);
		div *= 10;
		max_elem /= 10;	
	}

	for(int i=0;i<size;++i) {
		std::cout << arr[i] << std::endl;
	}


	delete [] copy_arr;
	delete [] count;
	

	return 0;
}
