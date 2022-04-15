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
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int l = min(a, b);
		int r = max(a, b);
		//int ans = (b - a) / 2;
		//int ans = INT_MIN;
		// int lsum = (b - (l + 1)) / 2;
		// int rsum = ();
		// for (int x = l; x <= r; x++)
		// {
		// 	int lsum = ceil((b - x) / (float)2);
		// 	int rsum = ceil((x - a) / (float)2);
		// 	ans = max(ans, rsum + lsum);
		// }
		if (a == b)
			cout << 0 << endl;
		else if (a < b)
		{
			// if (abs(a - b) % 2 == 0)
			// 	cout << 1 << endl;
			// else
			cout << ((b - a) / 2) + 1 << endl;
		}
		else if (a > b)
		{
			if ((a - b) % 2 == 0)
				cout << ((b - a) / 2) + 1 << endl;
			else
				cout << ((b - a) / 2) << endl;
		}
	}


	return 0;
}