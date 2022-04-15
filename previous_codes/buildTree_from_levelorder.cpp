#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class node {

public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void levelOrder(node*root) {

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << endl;
			q.pop();
			//insert a new null for the next level
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << temp->data << " ";

			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}

	}
	return;
}


node* buildTreeLevelOrder(vector<int> a)
{
	int n = a.size();
	int i = 0;
	node* root = new node(a[i++]);
	queue<node*> q;
	q.push(root);
	while (!q.empty() && i < n)
	{
		node* temp = q.front();
		q.pop();
		if (a[i] == -1)
			i++;
		else
		{
			temp->left = new node(a[i++]);
			q.push(temp->left);
		}
		if (a[i] == -1)
			i++;
		else
		{
			temp->right = new node(a[i++]);
			q.push(temp->right);
		}
	}
	return root;
}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		node* root = buildTreeLevelOrder(a);
		levelOrder(root);
	}


	return 0;
}