/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, flag = 0;
		cin >> n >> m;
		for (int i = 2; i <= (m / 2); i++)
		{
			if (m % i == 0)
			{
				int f = pow(i, n);
				/*int f = 1;
				for (int j = 0; j < n; j++)
				{
					f *= i;
				}
				if (f == m)
				{
					flag = 1;
					cout << i << endl;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (!flag)
			cout << -1 << endl;
	}


	return 0;
}*/

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
	while (T--) {
		int n, m, flag = 0;
		cin >> n >> m;
		int res = 0;
		res = pow(m, 1.0 / n);
		int z = pow(res, n);
		if (z == m)
			cout << res << endl;
		else
			cout << -1 << endl;
	}


	return 0;
}

class Solution {
public:
	int mySqrt(int x) {
		return pow(x, 1.0 / 2);
	}
};