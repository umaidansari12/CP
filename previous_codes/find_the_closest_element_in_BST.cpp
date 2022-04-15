#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

void printInOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root-> key << " ,";
	printInOrder(root->right);
}

Node* closestBST(Node* root, int target)
{
	Node* temp = root;
	Node* prev = NULL;
	int diff = INT_MAX;
	while (temp != NULL)
	{
		int curr_diff = abs(temp->key - target);
		if (current_diff == 0) {
			prev = temp;
		}
		if (curr_diff < diff)
		{
			diff = curr_diff;
			prev = temp;
		}
		if (temp->key < target)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	return prev;
}

void closestBSTrecur(Node* root, int target, int &diff, Node* prev)
{
	if (root == NULL)
		return;

	int curr_diff = abs(root->key - target);
	if (curr_diff < diff)
	{
		diff = curr_diff;
		prev = root;
	}
	if (root->key < target)
		closestBSTrecur(root->right, target, diff, prev);
	else
		closestBSTrecur(root->left, target, diff, prev);

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Node* root = NULL;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		root = insert(root, x);
	}
	cin >> x;
	int diff = INT_MAX;
	Node* value = closestBST(root, x);
	cout << value->key << endl;
	Node* prev = NULL;
	closestBSTrecur(root, x, diff, prev);
	cout << value->key << endl;

	return 0;
}