#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool r = binary_search(a.begin(), a.end(), x);
		if (r)
		{
			int l = lower_bound(a.begin(), a.end(), x) - a.begin();
			int u = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
			if (l != n && a[l] == x)
				cout << l << " ";
			if (u >= 0 && a[u] == x)
				cout << u << " ";
		}
		else
			cout << "-1 ";
		cout << endl;

	}


	return 0;
}