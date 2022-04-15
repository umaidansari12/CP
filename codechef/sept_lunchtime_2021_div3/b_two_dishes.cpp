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
		long long int n, a, b, c;
		cin >> n >> a >> b >> c;
		if (a >= n and b >= n)
		{
			cout << "YES\n";
		}
		else if (b >= n and c >= n)
		{
			cout << "YES\n";
		}
		else {
			int oneDish = min(a, b);
			b -= oneDish;
			int twoDish = min(b, c);
			if (oneDish + twoDish >= n)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}