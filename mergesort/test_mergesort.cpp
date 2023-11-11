#include <iostream>
#include "mergesort.h"
#include <random>
#include <chrono>
#include <vector>
#include <fstream>

constexpr int max_size = 16000;
constexpr int max_repetition = 1; 

int main() {
	using std::chrono::nanoseconds;
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::vector<nanoseconds> total(max_size);

	
	std::ofstream file("../graphs/data.txt");

	for(int count=0; count < max_repetition; ++count) {
		for(int size=1; size < max_size; ++size) {
			std::uniform_int_distribution<int> dist(-size, size);

			int* arr = new int[size];
			for(unsigned i=0; i < size; ++i) {
				arr[i] = dist(gen);
			}
			
			auto start = std::chrono::steady_clock::now();
			mergesort(arr, size);
			auto end = std::chrono::steady_clock::now();

			nanoseconds time = std::chrono::duration_cast<nanoseconds>(end - start);
			total[size] += time;
			delete [] arr;
		}

	}
	
	for(int size=1; size < max_size; ++size) {
		file << size << '\n' << total[size].count() / max_repetition-1 << std::endl;
	}
	file.close();


}
