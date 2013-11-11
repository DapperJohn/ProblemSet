#include "AVLTree.h"

#include <iostream>
#include <string>
#include <queue>

#include <cstdio>
#include <cstdlib>

//John Anny and Selby Kendrick
//CSC 3102 Sect 001
//November 7th, 2013
//Problem #3
//
//Description:
//Main program for AVL Tree Problem 

using namespace std;

int AVLTree::height(struct node * N){
	if (N == NULL) return 0;
	return N->height;
}

int AVLTree::height(){
	return height(root);
}

int AVLTree::size(struct node * node){
	if (node == NULL) return 0;
	else return (size(node->left) + 1 + size(node->right));
}

int AVLTree::max(int a, int b){
	return (a > b) ? a : b;
}

struct node * AVLTree::createNode(int key){
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->height = 1;
	node->size = 1;
	return (node);
}

struct node * AVLTree::rightRotate(struct node * y){
	struct node * x = y->left;
	struct node * T2 = x->right;

	// Do rotation
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	y->size = size(y);
	x->size = size(x);

	return x;
}

struct node * AVLTree::leftRotate(struct node * x){
	struct node * y = x->right;
	struct node * T2 = y->left;

	// Do rotation
	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	x->size = size(x);
	y->size = size(y);

	return y;
}

int AVLTree::getBalanceFactor(struct node * N){
	if (N == NULL) return 0;
	return height(N->left) - height(N->right);
}

struct node * AVLTree::min(struct node * node){
	struct node * current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

struct node * AVLTree::max(struct node * node){
	struct node * current = node;
	while (current->right != NULL)
		current = current->right;
	return current;
}

struct node * AVLTree::insert(struct node * node, int key){
	// Perform BST insertion
	if (node == NULL) return (createNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	// Update the height of inserted ancestor node
	node->height = max(height(node->left), height(node->right)) + 1;
	node->size = size(node);

	// Get the balance factor of the ancestor node
	int balance = getBalanceFactor(node);

	// If node is unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct node * AVLTree::insert(int key){
	if (root == NULL) {
		root = createNode(key);
		return root;
	}

	return insert(root, key);
}

struct node * AVLTree::erase(struct node * node, int key){
	// 1 PERFORM BST DELETE
	if (node == NULL) return node;

	if (key < node->key)
		node->left = erase(node->left, key);
	else if (key > node->key)
		node->right = erase(node->right, key);
	else {
		// One child case/No child case
		if ((node->left == NULL) || (node->right == NULL)) {
			struct node * temp = node->left ? node->left : node->right;

			// No child case
			if (temp == NULL) {
				temp = node;
				node = NULL;
			} else *node = *temp;   // One child case

			free(temp);
		} else {
			// Two child case
			struct node * temp = min(node->right);
			node->key = temp->key;
			node->right = erase(node->right, temp->key);
		}
	}

	//Single node case
	if (node == NULL) return node;

	// 2 UPDATE HEIGHT
	node->height = max(height(node->left), height(node->right)) + 1;
	node->size = size(node);

	// 3 GET BALANCE FACTOR
	int balance = getBalanceFactor(node);

	// 4 BALANCE AVL TREE FOR ALL CASES

	// Left Left Case
	if (balance > 1 && getBalanceFactor(node->left) >= 0)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && getBalanceFactor(node->right) <= 0)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && getBalanceFactor(node->left) < 0) {
		node->left = leftRotate(node->left);
		return rightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && getBalanceFactor(node->right) > 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct node * AVLTree::erase(int key){
	return erase(root, key);
}

bool AVLTree::search(struct node * node, int key){
	if (node == NULL) return false;

	if (node->key == key) return true;
	else if (key < node->key)
		search(node->left, key);
	else if (key > node->key)
		search(node->right, key);
}


struct node * AVLTree::successor(struct node * nodeX){
	struct node * nodeY = nodeX->parent;

	if (nodeX->right != NULL)
		return (min(nodeX->right));

	while (nodeY != NULL && nodeX == nodeY->right) {
		nodeX = nodeY;
		nodeY = nodeY->parent;
	}
	return nodeY;
}

struct node * AVLTree::predecessor(struct node * nodeX){
	if (nodeX->left != NULL)
		return (max(nodeX->left));
	struct node * nodeY = nodeX->parent;

	while (nodeY != NULL && nodeX == nodeY->left) {
		nodeX = nodeY; nodeY = nodeY->parent;
	}
	return nodeY;
}

bool AVLTree::search(int key){
	search(root, key);
}


void AVLTree::preOrderTraversal(struct node * root){
	if (root != NULL) {
		printf("%d ", root->key);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}


void AVLTree::preOrderTraversal(){
	preOrderTraversal(root);
}

void AVLTree::inOrderTraversal(struct node * root){
	if (root != NULL) {
		inOrderTraversal(root->left);
		printf("%d ", root->key);
		inOrderTraversal(root->right);
	}
}

void AVLTree::inOrderTraversal(){
	inOrderTraversal(root);
}

void AVLTree::print(){
	if (!root) return;
	int indent = 3 * height(root);
	int space = 2;
	cout << endl;
	std::cout.width(indent);
	//for(int i = 0; i < indent; ++i)
	//cout
	queue<node *> currentLevel, nextLevel;
	currentLevel.push(root);
	while (!currentLevel.empty()) {
		node * currNode = currentLevel.front();
		currentLevel.pop();
		if (currNode) {
			cout << currNode->key << "  ";
			std::cout.width(space);
			nextLevel.push(currNode->left);
			nextLevel.push(currNode->right);
		}
		if (currentLevel.empty()) {
			cout << endl;
			space += 1;
			std::cout.width(indent -= 3);
			swap(currentLevel, nextLevel);
		}
	}
}


int AVLTree::rank(struct node * x, int i){
	if (x == NULL) return 0;
	if (i < x->key) return rank(x->left, i);
	if (i == x->key) return (x->left->size + 1);
	// Problem may be in this return statement..
	return ((x->left->size + 1) + (rank(x->right, i)));
}

int AVLTree::rank(int i){
	rank(root, i);
}

int AVLTree::select(struct node * x, int i){
    if (x == NULL) return 0;
    if (x->left->size >= i)
        return select(x->left, i);
    if (x->left->size + 1 == i)
        return x->key;
    return select(x->right, i - 1 - (x->left->size));
}

int AVLTree::select(int i){
    return AVLTree::select(root, i);
}
