#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
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
		cin >> n >> m;//N  and M, number of important events in football and cricket match respectively.
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back({0, x});
		}
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			a.push_back({1, x});
		}
		int channel = 0, s = 0;
		sort(a.begin(), a.end(), comp);
		/*for (auto i : a)
			cout << i.first << " " << i.second << endl;
		cout << endl;*/
		for (int i = 0; i < n + m; i++)
		{
			if (channel != a[i].first)
			{
				channel = a[i].first;
				s++;
			}
		}
		cout << s << endl;
		//Find the total number of times you will have to switch between the channels.
	}


	return 0;
}