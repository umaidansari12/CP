#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solveRecur(long long int a[], int idx, int n, map<long long int, long long int> &m, int &res, vector<pair<int, int>> &operations, int operation, int x)
{
	if (idx == n)
	{
		long long int mx_size = 0;
		for (auto i : m)
		{
			mx_size = max(mx_size, i.second);
		}
		operations.push_back({mx_size, operation});
		return;
	}
	long long int xr = (a[idx] ^ x);
	m[xr]++;
	solveRecur(a, idx + 1, n, m, res, operations, operation + 1, x);
	m[xr]--;
	solveRecur(a, idx + 1, n, m, res, operations, operation, x);
}

void solve()
{
	int n, x;
	cin >> n >> x;
	long long int arr[n] = {0};
	map<long long int, long long int> cnt, op;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
		if (x != 0)
		{
			cnt[arr[i]^x]++;
			op[arr[i]^x]++;
		}
	}
	long long int equal = 0, operations = 0;
	for (auto u : cnt)
	{
		if (u.second > equal)
		{
			equal = u.second;
			operations = op[u.first];
		}
		else if (u.second == equal)
		{
			operations = min(operations, op[u.first]);
		}
	}
	cout << equal << " " << operations << endl;

}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
		// int n, res = 1, x; // operations = 0, x;
		// cin >> n >> x;
		// long long int a[n];
		// for (int i = 0; i < n; i++)
		// 	cin >> a[i];
		// map<long long int, long long int> m;
		// vector<pair<int, int>> operations;
		// solve(a, 0, n, m, res, operations, 0, x);
		// //cout << res << " " << operations << endl;
		// sort(operations.begin(), operations.end());
		// for (auto i : operations)
		// 	cout << i.first << " " << i.second << endl;
		// cout << endl;
		//cout << operations[0].first << " " << operations[0].second << endl;

	}

	return 0;
}
