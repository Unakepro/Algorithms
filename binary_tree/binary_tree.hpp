#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

struct Node {
	int value = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

void delete_node(Node* root) {
	if(root != nullptr) {	
		delete_node(root->left);
		delete_node(root->right);
		delete root;
	}
}


class Tree {
	Node* root = nullptr;	

public:	
	void insert(int v) {
		Node* ptr = root;
		Node* parent = nullptr;
	
		while(ptr != nullptr) {
			if(v < ptr->value) {
				parent = ptr;
				ptr = ptr->left;
			}
			else {
				parent = ptr;
				ptr = ptr->right;
			}
		}

		Node* inserted = new Node;
		inserted->value = v;
		

		if(parent == nullptr) {
			root = inserted;
		}
		else if(v < parent->value) {
			parent->left = inserted;
		}	
		else {
			parent->right = inserted;
		} 				
	}

	bool search(int v) {
		Node* start = root;
		
		while(start != nullptr) {
			if(start->value == v) {
				return true;
			}
			else {
				if(start->value > v) {
					start = start->left;
				}
				else {
					start = start->right;
				}
			}
		}

		return false;
	}
	
	~Tree() {
		delete_node(root);
	}

};




#endif
