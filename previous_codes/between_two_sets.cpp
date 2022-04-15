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
		int n, m, count = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		for (int i = a[n - 1]; i <= b[m - 1]; i++)
		{
			bool f = true;
			for (int j = 0; j < n; j++)
			{
				if (i % a[j] != 0)
				{
					f = false;
					break;
				}
			}
			if (f)
				for (int j = 0; j < m; j++)
				{
					if (b[j] % i != 0)
					{
						f = false;
						break;
					}
				}
			if (f)
				count++;
		}
		cout << count << endl;
	}


	return 0;
}