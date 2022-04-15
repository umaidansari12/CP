#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
public:
	string getBinaryString(int i, int n)
	{
		int c = 0;
		string s;
		while (i > 0)
		{
			s += (to_string(i % 2));
			i /= 2;
			c++;
		}
		while (c < n)
		{
			c++;
			s += '0';
		}
		reverse(s.begin(), s.end());
		return s;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>> s;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		s.insert(vector<int>());
		for (int i = 0; i <= pow(2, n) - 1; i++)
		{
			string binaryString = getBinaryString(i, n);
			vector<int> r;
			for (int i = 0; i < binaryString.size(); i++)
				if (binaryString[i] == '1')
					r.push_back(nums[i]);
			//sort(r.begin(),r.end());
			s.insert(r);
		}
		vector<vector<int>> res;
		for (auto i : s)
			res.push_back(i);
		return res;
	}
};

class Solution {
public:
	void findSubsets(int ind, vector<int> nums, vector<int>&ds, vector<vector<int>>&ans)
	{
		ans.push_back(ds);
		for (int i = ind; i < nums.size(); i++)
		{
			if (i != ind && nums[i] == nums[i - 1])
				continue;
			ds.push_back(nums[i]);
			findSubsets(i + 1, nums, ds, ans);
			ds.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> ds;
		findSubsets(0, nums, ds, ans);
		return ans;

	}
};

string getBinaryString(int i, int n)
{
	int count = 0;
	string s;
	while (i > 0)
	{
		s = s + (to_string(i % 2));
		i /= 2;
		count++;
	}
	while (count < n)
	{
		count++;
		s += '0';
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		set<vector<int>> s;
		s.insert(vector<int>());
		for (int i = 1; i <= pow(2, n) - 1; i++)
		{
			string binaryString = getBinaryString(i, n);
			//cout << binaryString << endl;
			vector<int> r;
			for (int i = 0; i < binaryString.size(); i++)
				if (binaryString[i] == '1')
					r.push_back(a[i]);
			s.insert(r);
		}
		for (auto i : s)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
		//cout << endl;

	}


	return 0;
}