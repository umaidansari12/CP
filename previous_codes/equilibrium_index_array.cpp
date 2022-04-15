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
		int n, ans = -1, leftsum = 0, sum = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 0; i < n; i++)
		{
			sum -= a[i];
			cout << sum << " " << leftsum << endl;
			if (sum == leftsum)
			{
				ans = i;
				break;
			}
			leftsum += a[i];
		}
		/*for (int i = 0; i < n; i++)
		{
			int leftsum = 0, rightsum = 0;
			for (int j = 0; j < i; j++)
				leftsum += a[j];
			for (int j = i + 1; j < n; j++)
				rightsum += a[j];
			if (leftsum == rightsum)
				ans = i;
		}*/
		cout << ans + 1 << "hello" << endl;
	}


	return 0;
}