#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve()
{
	int n;
	cin >> n;
	ll a[n], b[n], sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		sum2 += b[i];
	}
	if (sum1 >= sum2)
		return 0;
	if (sum1 == 0)
		return 1;
	if ((sum2 % sum1) == 0)
		return sum2 / sum1;
	return ceil((sum2 / sum1)) + 1;
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