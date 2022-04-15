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
		ll e, k, cnt = 0;
		cin >> e >> k;
		while ((e / k) > 0)
		{
			e = e / k;
			cnt++;
		}
		cout << cnt + 1 << endl;
	}


	return 0;
}