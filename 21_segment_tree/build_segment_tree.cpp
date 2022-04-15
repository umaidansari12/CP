#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class SegmentTreeNode {
public:
	int start, end, sum;
	SegmentTreeNode* left;
	SegmentTreeNode* right;
	SegmentTreeNode(int start, int end) {
		this->start = start;
		this->end = end;
		this->sum = 0;
		this->left = NULL;
		this->right = NULL;
	}
	// TC : O(n)
	SegmentTreeNode* buildTree(int nums[], int start, int end) {
		if (start > end)
			return NULL;
		else {
			SegmentTreeNode* ret = new SegmentTreeNode(start, end);
			if (start == end) {
				ret->sum = nums[start];
				return ret;
			}
			else {
				int mid = start + (end - start) / 2;
				ret->left = buildTree(nums, start, mid);
				ret->right = buildTree(nums, mid + 1, end);
				ret->sum = ret->left->sum + ret->right->sum;
			}
			return ret;
		}
		return NULL;
	}
};

class SegmentTreeOps {
public:
	SegmentTreeNode* root = NULL;
	SegmentTreeOps(int nums[], int start, int end) {
		SegmentTreeNode* r;
		root = r->buildTree(nums, start, end);
	}
	// TC : O(logn)
	void update(int idx, int val) {
		updateHelper(root, idx, val);
	}
	void updateHelper(SegmentTreeNode* root, int pos, int val) {
		// found leaf node to be updated
		if (root->start == root->end) {
			root->sum = val;
		}
		else {
			// parent nodes across the path
			int mid = root->start + (root->end - root->start) / 2;
			if (pos <= mid) {
				updateHelper(root->left, pos, val);
			}
			else {
				updateHelper(root->right, pos, val);
			}
			root->sum = root->left->sum + root->right->sum;
		}
	}

	// TC : O(logn)
	int sumRange(int l, int r) {
		return sumRangeHelper(root, l, r);
	}
	int sumRangeHelper(SegmentTreeNode* root, int start, int end) {
		// if you found out the node that matches your search return its value
		if (root->start == start and root->end == end) {
			return root->sum;
		}
		else {
			int mid = root->start + (root->end - root->start) / 2;// overflow conditions
			if (end <= mid) {
				// move left
				return sumRangeHelper(root->left, start, end);
			}
			else if (start >= mid + 1) {
				// move right
				return sumRangeHelper(root->right, start, end);
			}
			else {
				// consider both nodes
				return sumRangeHelper(root->left, start, mid) + sumRangeHelper(root->right, mid + 1, end);
			}
		}

	}
	void levelOrder(SegmentTreeNode* root) {
		if (!root)
			return;
		queue<SegmentTreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				cout << q.front()->sum << " ";
				if (q.front()->left)
					q.push(q.front()->left);
				if (q.front()->right)
					q.push(q.front()->right);
				q.pop();
			}
			cout << endl;
		}
	}

};



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		SegmentTreeOps ob(a, 0, n - 1);
		ob.levelOrder(ob.root);
		cout << ob.sumRange(1, 3) << endl;
		ob.update(1, 6);
		cout << ob.sumRange(1, 3) << endl;

	}


	return 0;
}