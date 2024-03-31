#include <iostream>
#include <vector>
#include "bubble_sort.hpp"

int main() {
	std::vector<int> xs = {2, 8, 12, 10, 3, 1};
	
	bubble_sort(xs);

	for(int i = 0; i < xs.size(); ++i) {
		std::cout << xs[i] << ' ';
	}

	return 0;
}
