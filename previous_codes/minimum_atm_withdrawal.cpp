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
		int n, x, ans = INT_MAX;
		cin >> n;
		vector<int> atm(n, 0);
		for (int i = 0; i < n; i++)
			cin >> atm[i];
		cin >> x;
		int sum = 0, end = 0, start = 0;
		map<int, int> m;
		while (end < n)
		{
			while (sum <= x && end < n)
				sum += atm[end++];
			while (sum > x && start < n)
			{
				sum -= atm[start++];
				ans = min(ans, end - start + 1);
			}
		}
		/*for (int i = 0; i < n; i++)
		{
			sum += atm[i];
			if (atm[i] == x)
				ans = 1;
			if (sum == x)
				ans = min(ans, i + 1);
			if (m.find(x - sum) != m.end())
				ans = min(ans, i - m[x - sum] + 1);
			if (m.find(sum) == m.end())
				m[sum] = i;

		}*/
		/*for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum += atm[j];
				if (sum >= x)
				{
					ans = min(ans, j - i + 1);
				}
			}
		}*/
		if (ans == INT_MAX)
			cout << -1 << endl;
		else
			cout << ans - 1 << endl;
	}


	return 0;
}