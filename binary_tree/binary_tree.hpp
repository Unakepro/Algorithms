#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

struct Node {
	int value = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinaryTree {
	Node* root = nullptr;	

public:	
	void insert(int v);
	bool search(int v);

	~BinaryTree();

};




#endif
