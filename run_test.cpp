#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>

#include "insertion_sort/insertion_sort.hpp"
#include "heapsort/heapsort.hpp"
#include "quicksort/quicksort.hpp"

using std::chrono::nanoseconds;

constexpr int max_size = 8000;
constexpr int max_repetition = 1;

std::random_device rd;
std::mt19937 gen(rd());

void measuring_data(void (*sort)(int*, int)) {
	std::vector<nanoseconds> total(max_size);

	std::ofstream file("graphs/data.txt");

	for(int count=0; count < max_repetition; ++count) {
		for(int size = 1; size < max_size; ++size) {
			std::uniform_int_distribution<int> dist(-size, size);
			
			int* arr = new int[size];
			for(unsigned i = 0; i < size; ++i) {
				arr[i] = dist(gen);
			}
			std::cout << size << '\n';

			auto start = std::chrono::steady_clock::now();
			sort(arr, size);	
			auto end = std::chrono::steady_clock::now();

			nanoseconds time = std::chrono::duration_cast<nanoseconds>(end - start);
			total[size-1] += time;
	
			delete [] arr;
		}

	}
	for(int size = 1; size < max_size; ++size) {
		file << total[size-1].count() / max_repetition << '\n'; 
	}
	file.close();
}



int main() {
	measuring_data(quicksort);
}
