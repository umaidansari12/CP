#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//brute force  solution is commented

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, p, x, y;
		cin >> n >> p;
		int position[p + 1] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			int left = max(x - y, 0);
			int right = min(x + y, p - 1);

			//int right = min(x+y+1,p+1);
			position[left] += 1;
			position[right + 1] -= 1;
			// for (int j = max(x - y, 0); j <= min(x + y, p); j++)
			// {
			// 	if (position[j] != 2)
			// 		position[j] += 1;
			// }
		}
		int len = 0, ans = -1;

		for (int i = 1; i < p + 1; i++)
		{
			position[i] += position[i - 1];
		}
		// for (auto i : position)
		// 	cout << i << " ";
		// cout << endl;
		for (auto i : position)
		{
			if (i >= 2 or i == 0)
			{
				len++;
			}
			else if (i == 1)
			{
				ans = max(ans, len);
				len = 0;
			}
			//cout << i << " ";
		}
		ans = max(ans, len);
		cout << ans << endl;
	}


	return 0;
}