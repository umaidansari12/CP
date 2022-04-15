#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <pair<ll, ll>> missingPoint(int n)
{
	map<ll, int> countx;
	map<ll, int> county;
	vector<pair<ll, ll>> r;
	ll x, y;
	for (int i = 1; i <= (4 * n) - 1; i++)
	{
		cin >> x >> y;
		countx[x]++;
		county[y]++;
	}
	x = 0, y = 0;
	auto i = countx.begin(), j = county.begin();
	while (i != countx.end() && j != county.end())
	{
		if ((i->second) % 2 == 1)
		{
			x = i->first;
		}
		if ((j->second) % 2 == 1)
		{
			y = j->first;
		}
		i++; j++;
	}
	r.push_back(make_pair((ll)x, (ll) y));
	return r;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <pair<ll, ll>> r = missingPoint(n);
		for (auto i : r)
		{
			cout << (i.first) << " " << (i.second) << endl;
		}

	}

	return 0;
}