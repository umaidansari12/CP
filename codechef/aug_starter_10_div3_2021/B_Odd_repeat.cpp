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
		long long int n, k, s;
		cin >> n >> k >> s;

		for (int i = 1, cnt = 1; i <= n; i++)
		{
			s -= cnt;
			cnt += 2;
		}
		cout << (s / (k - 1)) << endl;
	}

	return 0;
}