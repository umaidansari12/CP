#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int T;
	cin >> T;
	while (T--)
	{
		long long int n, q, l, r;
		cin >> n;
		vector<long long int> a(n), sum(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i != 0)
			{
				sum[i] += (a[i] + sum[i - 1]);
			}
			else
			{
				sum[i] = a[i];
			}
			//cout << sum[i] << " ";
		}
		//cout << endl;
		cin >> q;
		while (q--)
		{
			cin >> l >> r;
			/*if (l == 1)
				cout << sum[r - 1] << "\n";
			else
				cout << sum[r - 1] - sum[l - 2]<< "\n";*/
			cout << sum[r - 1] - sum[l - 1] + a[l - 1] << "\n";
			//cout << l << r << endl;
		}
	}


	return 0;
}