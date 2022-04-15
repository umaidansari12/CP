#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n, x, cnt = 0, pos = -1;
	cin >> n;
	set<int> s;
	int count[15] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		/*if (x <= 7)
		{
			s.insert(x);
		}
		if (s.size() == 7)
		{
			pos = i + 1;
		}*/
		if (x <= 7)
		{
			cnt++;
		}
		if (cnt == 7)
		{
			pos = i + 1;
			cnt++;
		}
		/*count[x]++;
		bool flag = true;
		for (int i = 1; i <= 7; i++)
		{
			if (count[i] == 0)
				flag = false;
		}
		if (flag)
			pos = i + 1;*/
	}
	return pos;
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
		cout << solve() << endl;
	}


	return 0;
}