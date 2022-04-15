#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, ans = 0;
		cin >> n;
		for (int i = 1; pow(2, i) <= n; i++)
		{
			int s = pow(2, i);
			if (s <= n)
				ans = s;
		}
		cout << ans << endl;
	}


	return 0;
}