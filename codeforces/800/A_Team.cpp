#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, count = 0;
	cin >> n;
	while (n--)
	{
		int x, y, z, cnt = 0;
		cin >> x >> y >> z;
		if (x == 1)
			cnt++;
		if (y == 1)
			cnt++;
		if (z == 1)
			cnt++;
		if (cnt >= 2)
			count++;
	}
	cout << count << endl;

	return 0;
}