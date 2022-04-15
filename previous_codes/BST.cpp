#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key) {
		this->key = key;
		left = right  = NULL;
	}
};

Node* insert(Node * root, int key) {
	if (root == NULL) {
		return new Node(key);
	}

	//rec case
	if (key < root->key) {
		root->left = insert(root->left, key);
	}
	else {
		root->right = insert(root->right, key);
	}
	return root;

}

bool isPresent(Node * root, int key) {
	//Complete this methodfalse
	if (root == NULL)
		return false;
	if (root->key == key)
		return true;
	else if (root->key < key)
	{
		return isPresent(root->right, key);
	}
	else if (root->key > key)
	{
		return isPresent(root->left, key);
	}
	return false;

}

void printInOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root-> key << " ,";
	printInOrder(root->right);
}


int main() {

	Node * root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

	for (int x : arr) {
		root = insert(root, x);
	}
	printInOrder(root);

	return 0;
}