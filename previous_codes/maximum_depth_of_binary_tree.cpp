#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}
//DFS using height

class Solution {
public:
	int maxDepth(TreeNode* root) {
		return (root != NULL) ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int count = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			count++;
			for (int i = 0; i < size; i++)
			{
				if (q.front()->left)
					q.push(q.front()->left);
				if (q.front()->right)
					q.push(q.front()->right);
				q.pop();
			}
		}
		return count;

	}
};