#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void solve(vector<vector<int>>&result, vector<int>&r, int n, int k, int sum, int prev)
{
	if (sum < 0)
		return;
	if (r.size() > k)
		return;
	if (sum == 0 && r.size() == k)
	{
		for (int j : r)
			cout << j << " ";
		cout << endl;
		result.push_back(r);
		return;
	}
	for (int i = 1; i < n; i++)
	{
		if (sum - i >= 0 && prev <= i)
		{
			r.push_back(i);
			solve(result, r, n, k, sum - i, i);
			r.pop_back();
		}
	}
	return;

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
		int n, k;
		cin >> n >> k;
		vector<vector<int>> result;
		vector<int> r;
		solve(result, r, n, k, n, 1);
		cout << result.size() << endl;
	}


	return 0;
}