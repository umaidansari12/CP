#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int coinChange(int i, int n, int sum, vector<int> a)
{
	if (sum == 0)
		return 0;
	if (sum < 0 or i >= n)
		return 0;
	return 1 + coinChange(i + 1, n, sum - a[i], a) + coinChange(i + 1, n, sum, a);

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cout << coinChange(0, n, m, a) << endl;



	}


	return 0;
}
