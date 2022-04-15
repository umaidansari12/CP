#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//aug long challenge div3
//problem no - 1

int solve()
{
	int g1, b1, s1, g2, b2, s2;
	cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

	int sum1 = g1 + s1 + b1;
	int sum2 = g2 + s2 + b2;

	if (sum1 > sum2)
		return 1;
	return 2;
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
		cout << solve() << '\n';
	}

	return 0;
}