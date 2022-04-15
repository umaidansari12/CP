#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n, m, x, throws = 0;
	cin >> n >> m >> x;
	vector<pair<int, int>> a;
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		cin >> throws;
		if (throws >= m)
		{
			res.push_back(i + 1);
			x--;
		}
		else
			a.push_back({throws, i + 1});
	}
	// for (auto i : a)
	// {
	// 	cout << i.first << " " << i.second << endl;
	// }
	if (x > 0)
	{
		sort(a.begin(), a.end());
		for (int i = (a.size() - x); i < a.size() ; i++)
			res.push_back(a[i].second);
	}

	sort(res.begin(), res.end());
	cout << res.size() << " ";
	for (auto i : res)
		cout << i << " ";
	cout << endl;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}