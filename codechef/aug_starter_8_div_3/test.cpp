#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, vector<int> > m;
	m[0].push_back(5);
	m[0].push_back(4);
	m[0].push_back(3);
	for (auto i : m)
	{
		for (auto j : i.second)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}