#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> s(n), f(n);
		vector<pair<int, int>> sf;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> f[i];
		}

		sort(s.begin(), s.end());
		sort(f.begin(), f.end());
		int cnt = 0, i = 0, j = 0;
		while (i < n && j < n)
		{
			if (s[i++] >= f[j])
			{
				j++;
			}
			else
			{
				cnt++;
			}
		}
		cout << cnt << endl;

	}


	return 0;
}