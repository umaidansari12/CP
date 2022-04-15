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
		ll n, cnt = 0;
		cin >> n;
		ll a[n];
		unordered_map<ll, ll> m;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}

		for (auto count : m)
		{
			if (count.second == 1)
				cnt += (n - count.second);
			else
				cnt += ((n - count.second) * count.second);
		}

		// double ans[n];
		// map<double, int> m;
		// for (int i = 0; i < n; i++)
		// {
		// 	cin >> a[i];
		// 	ans[i] = 1 / (double)a[i];
		// 	m[ans[i]]++;
		// }

		// sort(ans, ans + n, greater<double>());

		// for (int i = 1; i < n; i++)
		// {
		// 	if (ans[i] != ans[i - 1])
		// 		cnt += i;
		// 	else
		// 		cnt += (i - m[ans[i]] + 1);
		// }

		// for (int i = 0; i < n; i++)
		// {
		// 	cout << ans[i] << ' ';
		// }
		// cout << '\n';
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		if (i != j)
		// 		{
		// 			double op1 = (double)(a[i] - a[j]) / (double)a[i];
		// 			double op2 = (double)(a[i] - a[j]) / (double)a[j];
		// 			if (op1 < op2)
		// 				cnt++;
		// 		}

		// 	}
		// }
		cout << cnt << '\n';
		//cout << cnt * 2LL << '\n';
	}


	return 0;
}