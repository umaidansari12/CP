#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool canPlaceBirds(int b, int n, vector<int> a, int sep)
{
	int birds = 1, location = a[0];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - location >= sep)
		{
			birds++;
			location = a[i];
			if (birds == b)
				return true;
		}
	}
	return false;
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
		int n, b;
		cin >> n >> b;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		int s = 0, e = a[n - 1] - a[0], ans = -1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (canPlaceBirds(b, n, a, mid))
			{
				ans = mid;
				s = mid + 1;
			}
			else
				e = mid - 1;
		}
		cout << ans << endl;

	}


	return 0;
}