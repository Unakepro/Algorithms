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
		delete [] root;
	}
}


struct Tree {
	Node* root = nullptr;
	
	
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

	void print(Node* root) {
				

	}
	~Tree() {
		delete_node(root);
	}

};



int main() { 
	Tree tr1;
	for(int i=0;i<150;i+=10) {
		tr1.insert(i);
	} 
	for(int i=15;i>0;--i) {
		tr1.insert(i);
	} 

	
	tr1.print(tr1.root);	
		
	//for(int i=0;i<15;++i) {
	//	std::cout << tr1.search(i) << '\n';
	//}
	//for(int i=15;i>0;--i) {
	//	std::cout << tr1.search(i) << '\n';
	//}

}