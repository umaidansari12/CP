#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string getString(string s, string b)
{
	string o;
	for (int i = 0; i < s.size(); i++)
	{
		if (b[i] == '1')
			o += (s[i]);
	}
	return o;
}

string getBinaryString(int i, int n)
{
	string s;
	int c = 0;
	while (i > 0)
	{
		s = s + to_string(i % 2);
		i /= 2;
		c++;
	}
	while (c < n)
	{
		s += '0';
		c++;
	}
	reverse(s.begin(), s.end());
	return s;
}

vector<int> getSubset(vector<int> s, string b)
{
	vector<int> r;
	for (int i = 0; i < s.size(); i++)
	{
		if (b[i] == '1')
			r.push_back(s[i]);
	}
	return r;
}

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
		vector<int> a(n), r;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//r.push_back(0);
		for (int i = 1; i <= pow(2, n) - 1; i++)
		{
			string b = getBinaryString(i, n);
			vector<int> c = getSubset(a, b);
			for (auto i : c)
				cout << i << " ";
			cout << endl;
			//r.push_back(accumulate(c.begin(), c.end(), 0));
		}
		/*sort(r.begin(), r.end());
		for (auto i : r)
			cout << i << " ";*/
		cout << endl;
	}


	return 0;
}