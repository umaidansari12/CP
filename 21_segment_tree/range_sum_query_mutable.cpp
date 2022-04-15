class NumArraySolutionBrute {
public:
	vector<int> arr;
	NumArray(vector<int>& nums) {
		arr = nums;
	}

	void update(int index, int val) {
		arr[index] = val;
	}

	int sumRange(int left, int right) {
		int sum = 0;
		for (int i = left; i <= right; i++)
			sum += arr[i];
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArrayBetter {
public:
	vector<int> arr, pre;
	NumArray(vector<int>& nums) {
		arr = nums;
		pre = nums;
		pre[0] = arr[0];
		for (int i = 1; i < nums.size(); i++) {
			pre[i] = arr[i] + pre[i - 1];
		}

	}

	void update(int index, int val) {
		arr[index] = val;
		pre[index] = val;
		for (int i = 1; i < arr.size(); i++) {
			pre[i] = arr[i] + pre[i - 1];
		}
	}

	int sumRange(int left, int right) {
		if (left == 0)
			return pre[right];
		else
			return pre[right] - pre[left - 1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArray {
public:
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
	};
	SegmentTreeNode* root = NULL;
	NumArray(vector<int>& nums) {
		root = buildTree(nums, 0, nums.size() - 1);
	}

	SegmentTreeNode* buildTree(vector<int>&nums, int start, int end) {
		if (start > end)
			return NULL;
		else {
			SegmentTreeNode* ret = new SegmentTreeNode(start, end);
			if (start == end) {
				ret->sum = nums[start];
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

	void update(int index, int val) {
		updateHelper(root, index, val);
	}

	void updateHelper(SegmentTreeNode* root, int pos, int val) {
		if (root->start == root->end) {
			root->sum = val;
		}
		else {
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

	int sumRange(int left, int right) {
		return sumRangeHelper(root, left, right);
	}

	int sumRangeHelper(SegmentTreeNode* root, int left, int right) {
		if (root->start == left and root->end == right) {
			return root->sum;
		}
		else {
			int mid = root->start + (root->end - root->start) / 2;
			if (right <= mid) {
				return sumRangeHelper(root->left, left, right);
			}
			else if (left >= mid + 1)
				return sumRangeHelper(root->right, left, right);
			else {
				return sumRangeHelper(root->left, left, mid) + sumRangeHelper(root->right, mid + 1, right);
			}
		}
		return 0;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

struct SegmentTreeNode {
	int start, end, sum;
	SegmentTreeNode* left;
	SegmentTreeNode* right;
	SegmentTreeNode(int a, int b): start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};
class NumArray {
	SegmentTreeNode* root;
public:
	NumArray(vector<int> &nums) {
		int n = nums.size();
		root = buildTree(nums, 0, n - 1);
	}

	void update(int i, int val) {
		modifyTree(i, val, root);
	}

	int sumRange(int i, int j) {
		return queryTree(i, j, root);
	}
	SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
		if (start > end) return nullptr;
		SegmentTreeNode* root = new SegmentTreeNode(start, end);
		if (start == end) {
			root->sum = nums[start];
			return root;
		}
		int mid = start + (end - start) / 2;
		root->left = buildTree(nums, start, mid);
		root->right = buildTree(nums, mid + 1, end);
		root->sum = root->left->sum + root->right->sum;
		return root;
	}
	int modifyTree(int i, int val, SegmentTreeNode* root) {
		if (root == nullptr) return 0;
		int diff;
		if (root->start == i && root->end == i) {
			diff = val - root->sum;
			root->sum = val;
			return diff;
		}
		int mid = (root->start + root->end) / 2;
		if (i > mid) {
			diff = modifyTree(i, val, root->right);
		} else {
			diff = modifyTree(i, val, root->left);
		}
		root->sum = root->sum + diff;
		return diff;
	}
	int queryTree(int i, int j, SegmentTreeNode* root) {
		if (root == nullptr) return 0;
		if (root->start == i && root->end == j) return root->sum;
		int mid = (root->start + root->end) / 2;
		if (i > mid) return queryTree(i, j, root->right);
		if (j <= mid) return queryTree(i, j, root->left);
		return queryTree(i, mid, root->left) + queryTree(mid + 1, j, root->right);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);