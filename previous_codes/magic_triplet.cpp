#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, cnt = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; i++)
			{
				if (a[i] < a[j])
				{
					for (int k = i + 1; k < n; k++)
					{
						if (a[j] < a[k])
							cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}