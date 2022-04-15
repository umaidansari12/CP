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
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		int n = s.size();
		long long int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += ((i + 1) * (s[i] - 'a' + 1));
		}
		cout << ans << endl;
	}

	return 0;
}