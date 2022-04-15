#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n, a, b;
	cin >> n >> a >> b;

	return 2 * (180 + n) - (a + b);
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
		cout << solve() << endl;
	}


	return 0;
}