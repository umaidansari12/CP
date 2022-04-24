#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	//    Write your code here.
	vector<int> verticalOrder;

	if (root == NULL)
		return verticalOrder;

	map<int, map<int, vector<int>>> ds;

	queue<pair<TreeNode<int>*, pair<int, int>>> bfs;

	bfs.push({root, {0, 0}});
	while (!bfs.empty()) {
		TreeNode<int>* curr = bfs.front().first;
		int x = bfs.front().second.first;
		int y = bfs.front().second.second;

		ds[x][y].push_back(curr->data);

		bfs.pop();
		if (curr->left) {
			bfs.push({curr->left, {x - 1, y + 1}});
		}
		if (curr->right) {
			bfs.push({curr->right, {x + 1, y + 1}});
		}
	}

	for (auto x : ds) {
		for (auto y : x.second)
			for (auto z : y.second)
				verticalOrder.push_back(z);
	}

	return verticalOrder;
}

void verticalOrderHelper(TreeNode<int>* root, map<int, map<int, vector<int>>> &ds, int x, int y) {
	if (root == NULL)
		return;
	ds[x][y].push_back(root->data);
	verticalOrderHelper(root->left, ds, x - 1, y + 1);
	verticalOrderHelper(root->right, ds, x + 1, y + 1);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	//    Write your code here.
	vector<int> verticalOrder;

	if (root == NULL)
		return verticalOrder;

	map<int, map<int, vector<int>>> ds;

	verticalOrderHelper(root, ds, 0, 0);

	for (auto x : ds) {
		for (auto y : x.second)
			for (auto z : y.second)
				verticalOrder.push_back(z);
	}

	return verticalOrder;
}

vector < vector < int >> findVertical(node * root) {
	map < int, map < int, multiset < int >>> nodes;
	queue < pair < node * , pair < int, int >>> todo;
	todo.push({
		root,
		{
			0,
			0
		}
	}); //initial vertical and level
	while (!todo.empty()) {
		auto p = todo.front();
		todo.pop();
		node * temp = p.first;

		//x -> vertical , y->level
		int x = p.second.first, y = p.second.second;
		nodes[x][y].insert(temp -> data); //inserting to multiset

		if (temp -> left) {
			todo.push({
				temp -> left,
				{
					x - 1,
					y + 1
				}
			});
		}
		if (temp -> right) {
			todo.push({
				temp -> right,
				{
					x + 1,
					y + 1
				}
			});
		}
	}
	vector < vector < int >> ans;
	for (auto p : nodes) {
		vector < int > col;
		for (auto q : p.second) {
			col.insert(col.end(), q.second.begin(), q.second.end());
		}
		ans.push_back(col);
	}
	return ans;
}

class Solution {
public:
	void solve(TreeNode* root, map<int, map<int, multiset<int>>> &m, int col, int row)
	{
		if (!root)
			return;
		m[col][row].insert(root->val);
		solve(root->left, m, col - 1, row + 1);
		solve(root->right, m, col + 1, row + 1);
	}
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		map<int, map<int, multiset<int>>> m;
		solve(root, m, 0, 0);
		for (auto i : m)
		{
			res.push_back(vector<int>());
			for (auto j : i.second)
			{
				for (auto k : j.second)
					res.back().push_back(k);
			}
		}
		return res;

	}
};