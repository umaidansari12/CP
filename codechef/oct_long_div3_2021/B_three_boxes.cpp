#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + b + c) <= d) {
		cout << 1 << endl;
	}
	else if ((a + b) <= d or (a + c) <= d)
	{
		cout << 2 << endl;
	}
	else {
		cout << 3 << endl;
	}

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		// int a[3] = {0}, d;
		// for (int i = 0; i < 3; i++)
		// 	cin >> a[i];
		// cin >> d;

		// int sum = 0, bags = 1;
		// for (int i = 0; i < 3; i++) {
		// 	if (a[i] == d)
		// 	{
		// 		bags++;
		// 		continue;
		// 	}
		// 	if (sum + a[i] <= d)
		// 	{
		// 		sum += a[i];
		// 		continue;
		// 	}
		// 	else
		// 	{
		// 		sum = 0;
		// 		bags++;
		// 	}
		// }
		//cout << bags << endl;


	}
	return 0;
}