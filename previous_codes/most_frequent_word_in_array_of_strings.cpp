#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string frequentWord(vector<string> a, int n)
{
	unordered_map<string, pair<int, int>> m;
	//map<string, pair<int, int>> m;
	for (int i = 0; i < n; i++)
	{
		if (m.find(a[i]) == m.end())
		{
			m.insert({a[i], make_pair(i, 1)});
		}
		else
		{
			m[a[i]].second++;
		}
	}
	int idx = -1, count = 0;
	string ans;
	for (auto i : m)
	{
		if (count < i.second.second)
		{
			count = i.second.second;
			ans = i.first;
			idx = i.second.first;
		}
		else if (count == i.second.second)
		{
			//cout << idx << " ";
			if (idx < i.second.first)
			{
				idx = i.second.first;
				ans = i.first;
			}
		}
		cout << i.first << " " << i.second.first << " " << i.second.second << endl;
	}
	return ans;
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
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << frequentWord(a, n) << endl;
	}


	return 0;
}