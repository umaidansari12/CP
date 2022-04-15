#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <pair<int, int>>r;

void helptheman(int n, int from, int to, int aux)
{
	if (n == 1)
	{
		r.push_back(make_pair(from, to));
		return;
	}

	helptheman(n - 1, from, aux, to);
	r.push_back(make_pair(from, to));
	helptheman(n - 1, aux, to, from);
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
		int n, k;
		cin >> n >> k;
		helptheman(n, 1, 3, 2);
		cout << r[k - 1].first << " " << r[k - 1].second << endl;
		r.clear();
	}


	return 0;
}