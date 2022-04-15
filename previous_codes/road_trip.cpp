#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = -1, idx = -1;
		for (int i = 0; i < n; i++)
		{
			x--;

			if (ans <= a[i])
			{
				idx = i;
				ans = a[i];
			}
			//cout << ans << " " << i << " " << idx << endl;
			if (x == 0)
			{
				x += ans;
				cout << idx << " ";
				ans = 0;
			}
		}
		cout << endl;
	}


	return 0;
}
