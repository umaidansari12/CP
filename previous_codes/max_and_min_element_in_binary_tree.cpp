#include<bits/stdc++.h>
using namespace std;

// A tree node
struct node
{
	int data;
	struct node *left;
	struct node *right;

	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

// Returns maximum value in a given Binary Tree
int findMax(struct node* root);
// Returns minimum value in a given Binary Tree
int findMin(struct node* root);

void insert(struct node *root, int n1, int n2, char lr)
{
	if (root == NULL)
		return;
	if (root->data == n1)
	{
		switch (lr)
		{
		case 'L': root->left = new node(n2);
			break;
		case 'R': root->right = new node(n2);
			break;
		}
	}
	else
	{
		insert(root->left, n1, n2, lr);
		insert(root->right, n1, n2, lr);
	}
}
// Driver program to test above functions
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		struct node *root = NULL;
		while (n--)
		{
			char lr;
			int n1, n2;
			cin >> n1 >> n2;
			cin >> lr;
			if (root == NULL)
			{
				root = new node(n1);
				switch (lr) {
				case 'L': root->left = new node(n2);
					break;
				case 'R': root->right = new node(n2);
					break;
				}
			}
			else
			{
				insert(root, n1, n2, lr);
			}
		}

		cout << findMax(root) << " " << findMin(root) << endl;
	}
	return 0;
}
// } Driver Code Ends


// Returns maximum value in a given Binary Tree
void inordermin(struct node* root, int &mi)
{
	if (!root)
		return;
	inordermin(root->left, mi);
	mi = min(mi, root->data);
	inordermin(root->right, mi);
}
void inordermax(struct node* root, int &ma)
{
	if (!root)
		return;
	inordermax(root->left, ma);
	ma = max(ma, root->data);
	inordermax(root->right, ma);
}
int findMax(struct node* root)
{
// Your code goes here
	int ma = INT_MIN;
	inordermax(root, ma);
	return ma;
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
// Your code goes here
	int ma = INT_MAX;
	inordermin(root, ma);
	return ma;
}

int findMax1(struct node* root)
{
// Your code goes here
	if (!root)
		return INT_MIN;
	int res = root->data;
	int left = findMax(root->left);
	int right = findMax(root->right);
	return max(res, max(left, right));
}

// Returns minimum value in a given Binary Tree
int findMin1(struct node* root)
{
// Your code goes here
	if (!root)
		return INT_MAX;
	int res = root->data;
	int left = findMin(root->left);
	int right = findMin(root->right);
	return min(res, min(left, right));
}