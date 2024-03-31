#include <iostream>
#include "binary_tree.hpp"

int main() {
    BinaryTree tr;

    for(int i = 0; i < 50; ++i) {
        tr.insert(i);
    }
    
    for(int i = 0; i < 50; ++i) {
        std::cout << tr.search(i) << ' ';
    }
}