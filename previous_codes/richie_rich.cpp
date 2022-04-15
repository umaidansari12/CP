#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int a, b, x;
	cin >> a >> b >> x;
	return (b - a) / x;
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