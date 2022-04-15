#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	void solve(vector<int> &nums, vector<int>&ds, vector<vector<int>>&ans, vector<int>&freq)
	{
		if (ds.size() == nums.size())
		{
			ans.push_back(ds);
			return ;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (!freq[i])
			{
				ds.push_back(nums[i]);
				freq[i] = 1;
				solve(nums, ds, ans, freq);
				ds.pop_back();
				freq[i] = 0;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> ds;
		int n = nums.size();
		vector<int> freq(n, 0);
		solve(nums, ds, ans, freq);
		return ans;


	}
};


void printAllPermutationsOfGivenString(string& s, int l, int r, vector<string>& res, int &count)
{
	if (l == r)
	{
		res.push_back(s);
		//return;
	}
	count++;
	cout << count << endl;
	for (int j = l; j <= r; j++)
	{
		swap(s[l], s[j]);
		printAllPermutationsOfGivenString(s, l + 1, r, res, count);
		swap(s[l], s[j]);
	}


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
		string s;
		cin >> s;
		vector<string> res;
		int count = 0;
		printAllPermutationsOfGivenString(s, 0, s.size() - 1, res, count);
		sort(res.begin(), res.end());
		for (string r : res)
			cout << r << " ";
		cout << endl;

	}


	return 0;
}

/*class Solution {
public:
	void solve(vector<int>& nums, int l, int r, vector<vector<int>> &res)
	{
		if (l == r)
			res.push_back(nums);
		for (int i = l; i <= r; i++)
		{
			swap(nums[l], nums[i]);
			solve(nums, l + 1, r, res);
			swap(nums[l], nums[i]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		solve(nums, 0, nums.size() - 1, res);
		return res;

	}
};

class Solution {
public:
	void solve(vector<int>& nums, int l, int r, vector<vector<int>> &res)
	{
		if (l == r)
			res.push_back(nums);
		for (int i = l; i <= r; i++)
		{
			swap(nums[l], nums[i]);
			solve(nums, l + 1, r, res);
			swap(nums[l], nums[i]);
		}
	}
	string getPermutation(int n, int k) {
		vector<vector<int>> res;
		vector<int> nums(n, 0);
		for (int i = 1; i <= n; i++)
			nums[i - 1] = i;
		solve(nums, 0, nums.size() - 1, res);
		sort(res.begin(), res.end());
		string s;
		for (int i = 0; i < n; i++)
		{
			s += to_string(res[k - 1][i]);
		}
		return s;
	}
};*/