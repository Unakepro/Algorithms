#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>

struct AVLNode {
	int value=0;
	int balance=0;	
	AVLNode* parent=nullptr;
	AVLNode* left=nullptr;
	AVLNode* right=nullptr;
};


class AVLTree {
	AVLNode* root = nullptr;
	
	void update_balance(AVLNode* node, int add_v);
    void balance(AVLNode* node, int value);

    void rotation_right(AVLNode* ptr);
    void rotation_left(AVLNode* ptr);

public:
	void insert(int v);
	bool search(int v);

	~AVLTree();
};

#endif
