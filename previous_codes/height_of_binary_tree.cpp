class Solution {
public:
	int height(struct Node* node) {
		// code here
		if (node == NULL)
			return 0;
		int left = height(node->left) + 1;
		int right = height(node->right) + 1;
		return max(left, right);
	}
};

class Solution {
public:
	int solve(struct Node* node, int lvl)
	{
		queue<pair<struct Node*, int>> q;
		q.push(make_pair(node, lvl));
		while (!q.empty())
		{
			struct Node* t = q.front().first;
			lvl = q.front().second;
			q.pop();
			if (t->left)
				q.push(make_pair(t->left, lvl + 1));
			if (t->right)
				q.push(make_pair(t->right, lvl + 1));
		}
		return lvl;
	}
	int height(struct Node* node) {
		// code here
		int lvl = 0;
		return solve(node, lvl) + 1;
		// return lvl+1;
	}
};