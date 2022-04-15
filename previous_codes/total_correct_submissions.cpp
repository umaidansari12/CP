#include <bits/stdc++.h>

using namespace std;
using ll = long long;



void solve()
{
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 1; i <= (3 * n); i++)
	{
		string s;
		cin >> s;
		int x;
		cin >> x;
		m[s] += x;
	}
	vector<int> r;
	for (auto i : m)
		r.push_back(i.second);
	sort(r.begin(), r.end());
	for (auto i : r)
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
	while (t--)
	{
		solve();
	}


	return 0;
}