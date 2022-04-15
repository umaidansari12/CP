#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		long long int n, k, d, sum = 0, x, res;
		cin >> n >> k >> d;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			sum += x;
		}
		res = sum / k;
		if (res > d)
			cout << d << endl;
		else
			cout << res << endl;
	}


	return 0;
}