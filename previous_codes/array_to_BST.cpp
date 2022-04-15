#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<int> a, int l, int r)
{
	if (l > r)
		return;
	int mid = (l + r) / 2;
	cout << a[mid] << " ";
	solve(a, l, mid - 1);
	solve(a, mid + 1, r);

}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		solve(a, 0, n - 1);
		cout << endl;
	}


	return 0;
}

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void solve(vector<int>nums, int l, int r, vector<int> &pre)
	{
		if (l > r)
			return ;
		int mid = (l + r) / 2;
		pre.push_back(nums[mid]);
		solve(nums, l, mid - 1, pre);
		solve(nums, mid + 1, r, pre);
	}
	vector<int> sortedArrayToBST(vector<int>& nums) {
		vector<int> pre;
		solve(nums, 0, nums.size() - 1, pre);
		return pre;

	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* solve(vector<int> a, int l, int r)
	{
		if (l > r)
			return NULL;
		int mid = (l + r) / 2;
		TreeNode* root = new TreeNode(a[mid]);
		root->left = solve(a, l, mid - 1);
		root->right = solve(a, mid + 1, r);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return solve(nums, 0, nums.size() - 1);

	}
};