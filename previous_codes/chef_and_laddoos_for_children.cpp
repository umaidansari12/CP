#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int T;
	cin >> T;
	while (T--)
	{
		long long int n, k;
		cin >> n >> k;
		vector<long long int> a(n), ma, mi;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		long long int ans = INT_MAX;
		for (int i = 0; i + k - 1 < n; i++)
		{
			//cout << a[i] << " " << a[i + k - 1] << endl;
			ans = min(ans, a[i + k - 1] - a[i]);
		}
		cout << ans << endl;
		/*for (auto i : a)
			cout << i << " ";
		cout << endl;*/
		/*deque<long long int> q(k);
		int i = 0;
		for (i = 0; i < k; i++)
		{
			while (!q.empty() && a[i] >= a[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
		}
		for (; i < n; i++)
		{
			ma.push_back(a[q.front()]);
			while (!q.empty() && q.front() <= (i - k))
			{
				q.pop_front();
			}
			while (!q.empty() && a[i] >= a[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
		}
		ma.push_back(a[q.front()]);
		deque<long long int> q1(k);
		/*for (auto i : ma)
			cout << i << " ";
		cout << endl;
		i = 0;
		for (i = 0; i < k; i++)
		{
			while (!q1.empty() && a[i] <= a[q1.back()])
			{
				q1.pop_back();
			}
			q1.push_back(i);
		}
		for (; i < n; i++)
		{
			mi.push_back(a[q1.front()]);
			while (!q1.empty() && q1.front() <= (i - k))
			{
				q1.pop_front();
			}
			while (!q1.empty() && a[i] <= a[q1.back()])
			{
				q1.pop_back();
			}
			q1.push_back(i);
		}
		mi.push_back(a[q1.front()]);
		for (auto i : mi)
			cout << i << " ";
		cout << endl;
		long long int ans = INT_MAX;
		for (int i = 0; i < ma.size(); i++)
		{
			ans = min(ans, ma[i] - mi[i]);
		}
		/*	for (int i = 0; i < n - k; i++)
			{
				int ma = INT_MIN, mi = INT_MAX;
				for (int j = i; j < i + k; j++)
				{
					ma = max(ma, a[j]);
					mi = min(mi, a[j]);
				}
				ans = min(ans, ma - mi);
			}*/
		//cout << ans << endl;

	}


	return 0;
}