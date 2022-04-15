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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		int sum = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ans += (a[i] / x);
			sum += a[i];
		}
		cout << sum / x << " " << ans << endl;
	}

	return 0;
}