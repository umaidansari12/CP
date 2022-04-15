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
		int x, y;
		cin >> x >> y;
		string a;
		cin >> a;
		int ans = 0, curr = 0, ones = 0;
		for (int i = 0; i < 30; i++) {
			if (a[i] == '1')
			{
				ones++;
				curr++;
			}
			else if (a[i] == '0') {
				ans = max(ans, curr);
				curr = 0;
			}
		}
		ans = max(ans, curr);
		cout << (ones * x) + (ans * y) << endl;
	}

	return 0;
}