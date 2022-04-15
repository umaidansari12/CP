#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	Node()
}

void solve(vector<int>&r, Node* root)
{
	if (root == NULL)
		return;
	solve(r, root->left);
	r.push_back(root->data);
	solve(r, root->right);
}
vector<int> inOrder(Node* root)
{
	// Your code here
	vector<int> r;
	solve(r, root);
	return r;
}
vector<int> inOrder(Node* root)
{
	// Your code here
	vector<int> r;
	stack<Node*> s;
	Node* current = root;
	//s.push(current);

	while (current != NULL || !s.empty())
	{
		while (current != NULL)
		{
			s.push(current);
			current = current->left;
		}
		r.push_back(s.top()->data);
		current = s.top()->right;
		s.pop();
	}
	return r;
}

class Solution {
public:
	void solve(vector<int>&r, TreeNode* root)
	{
		if (root == NULL)
			return;
		solve(r, root->left);
		r.push_back(root->val);
		solve(r, root->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> r;
		solve(r, root);
		return r;

	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	return 0;
}

