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

void leftView(node* root, int level, map<int, int> &m)
{
	if (root == NULL)
		return;
	if (m.find(level) == m.end())
		m[level] = root->data;
	leftView(root->left, level + 1, m);
	leftView(root->right, level + 1, m);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node* root = levelOrderbuild();
	levelOrder(root);
	map<int, int> m;
	leftView(root, 0, m);
	for (auto i : m)
		cout << i.second << " ";
	cout << endl;


	return 0;
}