#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>
#include <cassert>
#include <algorithm>

#include "insertion_sort/insertion_sort.hpp"
#include "heapsort/heapsort.hpp"
#include "quicksort/quicksort.hpp"
#include "radixsort/radixsort.hpp"

using std::chrono::nanoseconds;

constexpr int max_size = 10000;
constexpr int max_repetition = 1;

std::random_device rd;
std::mt19937 gen(rd());


void generate_data(int* arr, int size) {
	std::uniform_int_distribution<int> dist(-size, size);	
	for(unsigned i = 0; i < size; ++i) {
		arr[i] = dist(gen);
	}

}


nanoseconds test_on_array(int* arr, int size, void(*sort)(int*, int)) {
	
	int* copy = new int[size];
	std::copy(arr, arr+size, copy);
	
	auto start = std::chrono::steady_clock::now();
	sort(copy, size);	
	auto end = std::chrono::steady_clock::now();
			
	assert(std::is_sorted(copy, copy+size));
	nanoseconds time = std::chrono::duration_cast<nanoseconds>(end - start);

	delete [] copy;

	return time;
}

long double get_data(nanoseconds obj) {
	return obj.count() / max_repetition;
} 

int main() {
	std::ofstream file("graphs/data.txt");
	file << "size insertion heapsort quicksort radixsort" << std::endl;

	std::vector<nanoseconds> total(4);
	for(int size = 100; size <= max_size; size += 100) {


		for(int count = 0; count < max_repetition; ++count) {
			int* arr = new int[size];
		
			generate_data(arr, size);		
			
			total[0] += test_on_array(arr, size, insertion_sort);
			total[1] += test_on_array(arr, size, heapsort);
			total[2] += test_on_array(arr, size, quicksort);
			total[3] += test_on_array(arr, size, radixsort);
				
			delete [] arr;
		}

		file << size << ' ' << get_data(total[0]) <<  ' '  << get_data(total[1]) <<  ' ' << get_data(total[2]) << ' ' <<
		get_data(total[3]) << '\n';

		std::cout << "Current size: " << size << std::endl;
		std::fill(total.begin(), total.end(), nanoseconds(0));
	}	
		
	file.close();
	
}


