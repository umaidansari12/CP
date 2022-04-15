#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ll a[n], pre[n];
	memset(a, 0, sizeof(a));
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			pre[i] = a[i];
		}
		else
		{
			pre[i] = pre[i - 1] + a[i];
		}
	}


	int q, t;
	cin >> q;
	while (q--)
	{
		int cnt = 0, i = 0;
		cin >> t;

		int low = 0 , high = n - 1, ans = -1, mid;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (a[mid] <= t)
			{
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		cout << ans + 1 << ' ' << pre[ans] << '\n';
		// int idx = upper_bound(a, a + n, t) - a;
		// cout << idx << ' ' << pre[idx - 1] << '\n';
		// for (i = 0; i < n; i++)
		// 	if (a[i] <= t)
		// 	{
		// 		cnt++;
		// 	}
		// 	else
		// 		break;
		// cout << cnt << ' ' << pre[i - 1] << '\n';

	}


	return 0;
}