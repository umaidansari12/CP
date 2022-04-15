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
		long long int n, count = 0, ans = 0;
		cin >> n;
		// while (n >= 1) {
		// 	if (n % 2 == 1) {
		// 		count++;
		// 	}
		// 	n /= 2;
		// }
		//cout << count << endl;
		count = __builtin_popcountl(n);
		for (int i = 0; i < count; i++) {
			ans += pow(2, i);
		}
		cout << ans << endl;
	}

	return 0;
}