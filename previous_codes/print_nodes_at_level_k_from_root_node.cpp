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

void kDistanceNodes(node* root, int k)
{
	if (root == NULL)
		return;
	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}
	kDistanceNodes(root->left, k - 1);
	kDistanceNodes(root->right, k -  1);
}


void search(node* root, int target, node* &target_node)
{
	if (root == NULL)
		return ;
	if (root->data == target)
	{
		target_node = root;
		return;
	}
	search(root->left, target, target_node);
	search(root->right, target, target_node);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node* root = levelOrderbuild();
	levelOrder(root);
	cout << endl;
	int k, target;
	cin >> k >> target;
	node* target_node = NULL;
	search(root, target, target_node);
	if (target_node == NULL)
		cout << "Yes" << endl;
	levelOrder(target_node);
	cout << endl;
	cout << target_node->data << endl;
	kDistanceNodes(target_node, k);


	return 0;
}