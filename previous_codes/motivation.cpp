#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, ans;
		cin >> n >> x;
		vector<pair<int, int>> arr(n);
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[i].first = a;
			arr[i].second = b;
		}
		sort(arr.begin(), arr.end(), comp);
		for (int i = 0; i < n; i++)
		{
			if (x >= arr[i].first)
			{
				ans = arr[i].second;
				break;
			}
		}
		cout << ans << endl;
	}


	return 0;
}