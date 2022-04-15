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
		int n;
		cin >> n;
		string res = "abcdefghijklmnop";
		string a;
		cin >> a;
		for (int i = 0; i < n / 4; i++)
		{
			int l = 0, h = 15, m = (l + h) / 2;
			//cout << l << " " << m << " " << h << " " << endl;
			for (int j = 4 * i; j < (4 * i) + 4; j++)
			{
				m = (l + h) / 2;
				if (a[j] == '0')
					h = m - 1;
				else if (a[j] == '1')
					l = m + 1;
				//cout << l << " " << m << " " << h << " " << endl;

			}
			cout << res[l];
		}
		cout << endl;

	}


	return 0;
}