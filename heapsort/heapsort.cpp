#include <iostream>
#include <vector>


void fix(std::vector<int>& arr, int index) {
	int l_child = 2*index+1;
	int r_child = 2*index+2;

	if(l_child < arr.size() && r_child < arr.size()) {
		int max_child = arr[l_child] >= arr[r_child] ? l_child: r_child;

		if(arr[index] < arr[max_child]) {
			std::swap(arr[index], arr[max_child]);
			fix(arr, max_child);	
		}
	}
	else if(l_child < arr.size()) {
		if(arr[index] < arr[l_child]) {
			std::swap(arr[index], arr[l_child]);
			fix(arr, l_child);
		}
	}
}



void make(std::vector<int>& arr) {
	for(int i = arr.size()-1 ; i >= 0; --i) {
		fix(arr, i);
	}
}



void heapsort(std::vector<int>& arr, std::vector<int>& output) {

	make(arr);


	while(arr.size() != 0) {
		
		output[arr.size()-1] = arr[0];
		
		std::swap(arr[0], arr[arr.size()-1]);
		arr.pop_back();
		fix(arr, 0);
	}
}



int main() {
	std::vector<int> xs = {2, 15, 37, 141, 26, 13, 174};
	std::vector<int> output(xs.size());
	
	heapsort(xs, output);

	for(int i = 0; i < output.size(); ++i) {
		std::cout << output[i] << ' ';
	}
		


	return 0;
}

