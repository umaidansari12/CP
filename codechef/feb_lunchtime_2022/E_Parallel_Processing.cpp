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
		long long int a[n] = {0}, pre[n] = {0}, suff[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) {
				pre[i] = a[i];
			}
			else {
				pre[i] = pre[i - 1] + a[i];
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			if (i == (n - 1)) {
				suff[i] = a[i];
			}
			else {
				suff[i] = suff[i + 1] + a[i];
			}
		}
		long long int ans = max(pre[n - 1], suff[0]);
		for (int i = 0; i < n - 1; i++) {
			ans = min(max(pre[i], suff[i + 1]), ans);
		}
		cout << ans << endl;
	}


	return 0;
}
