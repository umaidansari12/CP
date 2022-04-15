#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), pre(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0)
			{
				pre[i] = a[i];
			}
			else
			{
				pre[i] = max(a[i], pre[i - 1]);
			}
		}

		vector<pair<int, int>> r;
		for (int i = 1; i < n; i++)
		{
			int ans1 = INT_MAX, ans2 = INT_MAX;
			for (int j = i + 2; j < n - 1; j++)
			{
				ans1 = min(pre[i + 1], pre[i - 1]);
				ans2 = min(pre[j + 1], pre[j - 1]);
				cout << i << " " << j << endl;
			}
			r.push_back({ans1, ans2});
		}
		for (auto i : r)
			cout << i.first << " " << i.second << endl;
	}


	return 0;
}