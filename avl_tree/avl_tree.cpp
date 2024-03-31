#include <iostream>
#include "avl_tree.hpp"

void AVLTree::update_balance(AVLNode* node, int add_v) {
    node->balance += add_v;

    if(node->balance == -2) {
        balance(node, -2);
    }
    else if(node->balance == 2) {
        balance(node, 2);
    }
    else {
        if (node != root && node->balance != 0) {

            if(node->parent->left == node) {
                update_balance(node->parent, -1);
            }
            else {
                update_balance(node->parent, 1);
            }
        }
    }
}

void AVLTree::balance(AVLNode* node, int value) {
    if(value == -2) {
        if(node->left->balance == -1) {
            rotation_right(node);
        }
        else if(node->left->balance == 1) {
            rotation_left(node->left);
            rotation_right(node);
        }
    }
    else {
        if(node->right->balance == 1) {
            rotation_left(node);
        }
        else if(node->right->balance == -1) {
            rotation_right(node->right);
            rotation_left(node);
        }
    }
}

void AVLTree::rotation_right(AVLNode* ptr) {
    AVLNode* tmp = ptr;

    ptr = tmp->left;

    tmp->left = ptr->right;
    if(tmp->left != nullptr) {
        tmp->left->parent = tmp;
    }

    ptr->right = tmp;


    if(tmp->parent == nullptr) {
        tmp->parent = ptr;
        ptr->parent = nullptr;
        root = ptr;
    }
    else {
        ptr->parent = tmp->parent;
        
        if(tmp->parent->left == tmp) {
            tmp->parent->left = ptr;
        }
        else {
            tmp->parent->right = ptr;
        }
        
        tmp->parent = ptr;
    }

    tmp->balance = 0;
    ptr->balance = 0;

}

void AVLTree::rotation_left(AVLNode* ptr) {

    AVLNode *tmp = ptr;

    ptr = tmp->right;

    tmp->right = ptr->left;
    if(tmp->right != nullptr) {
        tmp->right->parent = tmp;
    }

    ptr->left = tmp;


    if(tmp->parent == nullptr) {
        tmp->parent = ptr;
        ptr->parent = nullptr;
        root = ptr;
    }
    else {
        ptr->parent = tmp->parent;
        
            if(tmp->parent->right == tmp) {
            tmp->parent->right = ptr;
        }
        else {
            tmp->parent->left = ptr;
        }
        tmp->parent = ptr;
    }

    tmp->balance = 0;
    ptr->balance = 0;
}


void AVLTree::insert(int v) {
    AVLNode* parent = nullptr;
    AVLNode* ptr = root;
    
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
    
    AVLNode* inserted = new AVLNode;
    inserted->value = v;	

    if(parent == nullptr) {
        root = inserted;
    }
    else {
        if(v < parent->value) {
            parent->left = inserted;
            parent->left->parent = parent;
            update_balance(parent, -1);
        }
        else {
            parent->right = inserted;
            parent->right->parent = parent;
            update_balance(parent, 1);
        }
    }	

}
	
bool AVLTree::search(int v) {
    AVLNode* start = root;		

    while(start != nullptr) {
        if(start->value == v) {
            return true;
        }
        else {
            if(v < start->value) {
                start = start->left;
            }
            else {
                start = start->right;
            }
        }
    }
    return false;
}

void destruct_avlnode(AVLNode* root) {
	if(root != nullptr) {
		destruct_avlnode(root->left);
		destruct_avlnode(root->right);
		delete root;	
	}
}

AVLTree::~AVLTree() {
    destruct_avlnode(root);
}