#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	/*if(a.second==b.second)
		return a.firstb.first*/
	/*if (a.second == b.second)
		return a.first < b.first;*/
	return a.second > b.second;
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
		int n, x;
		cin >> n;
		vector<int> count(61, 0);
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			count[x]++;
		}
		for (int i = 0; i < 61; i++)
		{
			if (count[i] != 0)
				ans.push_back({i, count[i]});
		}
		stable_sort(ans.begin(), ans.end(), cmp);
		for (int i = 0; i < ans.size(); i++)
		{
			while (ans[i].second--)
				cout << ans[i].first << " ";
		}
		cout << endl;
	}


	return 0;
}