#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve()
{
	ll n;
	cin >> n;
	ll ans = 0;
	while (n)
	{
		ans = max(ans, n % 10);
		n /= 10;
	}
	return ans;
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