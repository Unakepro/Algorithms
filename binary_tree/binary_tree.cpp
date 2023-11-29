#include <iostream>
#include "binary_tree.hpp"


int main() { 
	Tree tr1;

	for(int i=1;i<=15;++i) {
		tr1.insert(i);
	}
	
	for(int i=15;i>0;--i) {
		std::cout << tr1.search(i) << '\n';
	}
	
}
