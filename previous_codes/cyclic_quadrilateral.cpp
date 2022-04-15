#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + c) == 180 and (b + d) == 180)
		return true;
	return false;
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
		if (solve())
			cout << "Yes\n";
		else
			cout << "No\n";
	}


	return 0;
}