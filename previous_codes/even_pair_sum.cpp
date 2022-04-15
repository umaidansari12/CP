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
	//vector<vector<int>> dp(10000, vector<int>(10000, -1));
	while (T--)
	{
		long long int x, y, ans = 0, xe, xo, ye, yo;
		cin >> x >> y;
		/*for (int i = 1; i <= x; i++)
		{
			for (int j = 1; j <= y; j++)
			{
				if ((i + j) % 2 == 0)
				{
					ans++;
					//dp[i][j] == ans;
				}
				//else if
			}

		}*/
		xe = x / 2;
		xo = x - xe;
		ye = y / 2;
		yo = y - ye;
		ans = (xe * ye) + (xo * yo);
		cout << ans << endl;
	}


	return 0;
}