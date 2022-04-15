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
	while (t--) {
		int n;
		cin >> n;
		long long int a[n] = {0}, pre[n] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0)
				pre[i] = a[i];
			else
				pre[i] = a[i] + pre[i - 1];
		}
		long long int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			ans = min(ans, pre[i]);
		}
		cout << ans << endl;

	}


	return 0;
}