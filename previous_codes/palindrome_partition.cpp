#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Since, we are listing out all the partitions ( and not counting them), we need to do brute force here.

Think of recursion.

When on index i, you incrementally check all substring starting from i for being palindromic. If found, you recursively solve the problem for the remaining string and add it to your solution. Start this recursion from starting position of the string.

PS: You can optimize your solution by not computing the answer for same index multiple times using Dynamic Programming.
*/

bool isPalindrome(string s)
{
	int n = s.size(), i = 0, j = n - 1;
	while (i < n && j >= (n / 2))
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

void palindromePartition(string s, int n, string res)
{
	for (int i = 1; i <= n; i++)
	{
		string p = s.substr(0, i);
		if (isPalindrome(p))
		{
			if (i == n)
			{
				res += p;
				cout << res << endl;
				return;
			}
			palindromePartition(s.substr(i, n - i), n - i, res + p + " ");
		}
	}
}


class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > res;
		vector<string> path;
		func(0, s, path, res);
		return res;
	}

	void func(int index, string s, vector<string> &path,
	          vector<vector<string> > &res) {
		if (index == s.size()) {
			res.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i) {
			if (isPalindrome(s, index, i)) {
				path.push_back(s.substr(index, i - index + 1));
				func(i + 1, s, path, res);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};

class Solution {
public:
	bool isPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i <= j)
			if (s[i++] != s[j--])
				return false;
		return true;
	}
	void solve(int ind, string s, vector<string>&ds, vector<vector<string>>&ans)
	{
		if (ind == s.size())
		{
			ans.push_back(ds);
			return;
		}
		for (int i = ind; i < s.size(); i++)
		{
			if (isPalindrome(s.substr(ind, i - ind + 1)))
			{
				ds.push_back(s.substr(ind, i - ind + 1));
				solve(i + 1, s, ds, ans);
				ds.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> ds;
		solve(0, s, ds, ans);
		return ans;
	}
};

class Solution {
public:
	bool isPalindrome(string s)
	{
		int n = s.size(), i = 0, j = n - 1;
		while (i < n && j >= (n / 2))
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void solve(string s, int n, vector<string>&r, vector<vector<string>>&res)
	{
		for (int i = 1; i <= n; i++)
		{
			string p = s.substr(0, i);
			if (isPalindrome(p))
			{
				if (i == n)
				{
					r.push_back(p);
					res.push_back(r);
					r.pop_back();
					//r.erase(r.begin(),r.end());
					return;
				}
				r.push_back(p);
				solve(s.substr(i, n - i), n - i, r, res);
				r.pop_back();

			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> r;
		solve(s, s.size(), r, res);
		return res;

	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s, res;
		cin >> s;
		//cout << isPalindrome(s) << endl;
		palindromePartition(s, s.size(), res);
	}


	return 0;
}

class Solution {
public:
	bool isPalindrome(string s)
	{
		int n = s.size(), i = 0, j = n - 1;
		while (i < n && j >= (n / 2))
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void solve(string s, int n, vector<string>&r, vector<vector<string>>&res)
	{
		for (int i = 1; i <= n; i++)
		{
			string p = s.substr(0, i);
			if (isPalindrome(p))
			{
				if (i == n)
				{
					r.push_back(p);
					res.push_back(r);
					r.pop_back();
					//r.erase(r.begin(),r.end());
					return;
				}
				r.push_back(p);
				solve(s.substr(i, n - i), n - i, r, res);
				r.pop_back();

			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> r;
		solve(s, s.size(), r, res);
		return res;

	}
};