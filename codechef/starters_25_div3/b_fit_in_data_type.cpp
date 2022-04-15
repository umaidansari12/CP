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
		int n, x;
		cin >> n >> x;
		/*if ((x / n) == 0)
			cout << (x % n) << endl;
		else if ((x / n) >= 1 and (x % n) == 0)
			cout << 0 << endl;
		else
			cout << (x % n) - 1 << endl;*/
		if (x <= n)
			cout << x << endl;
		else
			cout << (x % (n + 1)) << endl;
	}


	return 0;
}