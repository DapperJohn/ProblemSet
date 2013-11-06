#include <cstdio>

struct node {
	int key;
	int size;
	struct node * left;
	struct node * right;
	struct node * parent;
	int height;
};

class AVLTree
{
	private:
		struct node * root = NULL;

		int height(struct node * N);

		struct node * createNode(int key);
		struct node * successor(struct node * nodeX);
		struct node * predecessor(struct node * nodeX);
		int getBalanceFactor(struct node * N);
		struct node * rightRotate(struct node * y);
		struct node * leftRotate(struct node * x);

		int max(int a, int b);

		//port over
		int size(struct node * node);

		struct node * insert(struct node * node, int key);
		struct node * erase(struct node * root, int key);

		bool search(struct node * root, int key);

		struct node * min(struct node * node);
		struct node * max(struct node * node);

		void inOrderTraversal(struct node * root);
		void preOrderTraversal(struct node * root);

		int rank(struct node * x, int i);
		int select(struct node * x, int i);
	public:
		int height();

		struct node * insert(int key);
		struct node * erase(int key);

		void inOrderTraversal();
		void preOrderTraversal();

		bool search(int key);

		int rank(int i);
        int select(int i);

		void print();
};