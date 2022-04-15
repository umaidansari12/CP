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
		long long int h, n;
		cin >> h >> n;
		long long int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int len = INT_MAX;
		for (int i = 0; i < n; i++) {
			long long int sum = 0;
			for (int j = i; j < n; j++) {
				sum += a[j];
				if (sum == h)
				{
					len = min(len, j - i + 1);
					break;
				}
			}
		}
		if (len == INT_MAX)
			cout << -1 << endl;
		else
			cout << len << endl;
	}

	return 0;
}