#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

class HDPair {
public:
	int height;
	int diameter;
};

node* buildTree()
{

	int d;
	cin >> d;
	if (d == -1)
		return NULL;
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

node* levelOrderbuild()
{
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* current = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1)
		{
			current->left = new node(c1);
			q.push(current->left);
		}
		if (c2 != -1)
		{
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}

void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

int height(node* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

//O(N^2) as height is calculated for every node's left and right subtree
int diameterOfTree(node* root)
{
	if (root == NULL)
		return 0;
	int d1 = height(root->left) + height(root->right);
	int d2 = diameterOfTree(root->left);
	int d3 = diameterOfTree(root->right);
	int d = max(d1, max(d2, d3));
	return d;
}

HDPair optDiameter(node* root)
{
	HDPair p;
	if (root == NULL)
	{
		p.height = p.diameter = 0;
		return p;
	}

	HDPair Left = optDiameter(root->left);
	HDPair Right = optDiameter(root->right);
	p.height = 1 + max(Left.height, Right.height);
	p.diameter = max(Left.height + Right.height, max(Left.diameter, Right.diameter));
	return p;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node *root = levelOrderbuild();
	levelOrder(root);
	cout << diameterOfTree(root) << endl;
	cout << optDiameter(root).diameter << endl;


	return 0;
}