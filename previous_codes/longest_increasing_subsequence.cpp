#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(vector<int>&a, int j, int prev, int n)
{
	if (j >= 0 && j < n && a[j] >= prev)
		return true;
	return false;
}

int longestSubsequence(int n, int a[])
{
	// your code here
	int ma = 1;
	vector<int> lis(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((a[i] > a[j]) && (lis[i] <= lis[j]))
			{
				lis[i] = 1 + lis[j];
				ma = max(ma, lis[i]);
			}
		}
	}
	return ma;
}

int longestSubsequenceBS(int n, vector<int> a)
{
	// your code here
	vector<int> res;
	res.push_back(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (res.back() < a[i])
			res.push_back(a[i]);
		else
		{
			int ind = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
			res[ind] = a[i];
		}
	}
	return res.size();
}


void longestIncreasingSubsequence(vector<int>&a, vector<vector<int>>&res, vector<int>&r, int j, int prev, int n)
{
	r.push_back(a[j]);
	for (int i = j + 1; i < n; i++)
	{
		if (a[i] > prev)
		{
			r.push_back(a[i]);
		}
		if (i == n - 1)
		{
			res.push_back(r);
			r.clear();
		}
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
		int n, ma = 0;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		/*int res = 0;
		for (int i = 0; i < n; i++)
		{
			int cnt = 1, prev = arr[i];
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] > prev)
				{
					cnt++;
					//prev = arr[j];
				}
			}
			res = max(res, cnt);
		}
		cout << res << endl;
		vector<int> r;
		vector<vector<int>>res;
		for (int i = 0; i < n; i++)
		{
			longestIncreasingSubsequence(arr, res, r, i, arr[i] , n);
		}

		for (auto i : res)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
		vector<int> lis(n, 1);

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if ((arr[i] > arr[j]) && (lis[i] <= lis[j]))
				{
					lis[i] = 1 + lis[j];
					ma = max(ma, lis[i]);
				}
			}
		}
		cout << ma << endl;*/
		cout << longestSubsequenceBS(n, arr) << endl;

	}


	return 0;
}