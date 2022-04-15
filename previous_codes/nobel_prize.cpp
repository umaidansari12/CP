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
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a[x - 1]++;
		}
		bool f = false;
		for (int i = 0; i < m; i++)
		{
			if (a[i] == 0)
			{
				f = true;
				break;
			}
		}
		if (f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}