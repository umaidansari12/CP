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
		int ans = 0;
		char curr = '1';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == curr) {
				continue;
			}
			if (s[i] != curr and curr == '1')
			{
				ans++;
				curr = '0';
				continue;
			}
			if (s[i] != curr and curr == '0')
			{
				ans++;
				curr = '1';
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
}