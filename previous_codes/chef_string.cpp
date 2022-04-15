#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll count_strings(vector <ll> &strings)
{
	ll count = 0;
	for (int i = 1; i < strings.size(); i++)
	{
		if (strings[i] != strings[i - 1])
		{
			count += (abs(strings[i] - strings[i - 1]) - 1);
		}
	}
	return count;
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
		vector <ll> strings(n);
		for (int i = 0; i < n; i++)
		{
			cin >> strings[i];
		}
		cout << count_strings(strings) << endl;
	}


	return 0;
}