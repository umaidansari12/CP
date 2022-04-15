#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	long long int a, b, c, m;
	cin >> a >> b >> c >> m;
	if (m == 0)
	{
		cout << "YES\n";
		return;
	}
	long long int countA = 0, countB = 0, countC = 0;
	countA = a / (long long int)2;
	countB = b / (long long int)2;
	countC = c / (long long int)2;
	if ((countA + countB + countC) == m)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();

	}


	return 0;
}