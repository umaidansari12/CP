#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(Node* root, vector<int>&r, int level, int& m)
{
	if (root == NULL)
		return;
	if (m < level)
	{
		r.push_back(root->data);
		m = level;
	}
	solve(root->left, r, level + 1, m);
	solve(root->right, r, level + 1, m);
}

vector<int> leftView(Node *root)
{
	// Your code here
	vector<int> r;
	int m = 0;
	solve(root, r, 1, m);
	return r;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}