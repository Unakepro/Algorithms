#include <iostream>
#include <vector>


int main() {
	std::vector<int> xs = {2, 8, 12, 10, 3, 1};
	
	for(int i =  0; i < xs.size(); ++i) {
		for(int j = 0; j < xs.size()-i-1; ++j) {
			if(xs[j] > xs[j+1]) {
				std::swap(xs[j], xs[j+1]);
			}
		} 
	}

	for(int i = 0; i < xs.size(); ++i) {
		std::cout << xs[i] << ' ';
	}

	return 0;
}
