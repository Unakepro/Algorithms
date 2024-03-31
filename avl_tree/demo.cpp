#include <iostream>
#include "avl_tree.hpp"


int main() {
	AVLTree tr1;
    tr1.insert(14);
    tr1.insert(12);
	tr1.insert(13);	

    std::cout << tr1.search(12) << std::endl;   
}

