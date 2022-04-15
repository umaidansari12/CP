#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve1()
{
	set<int> s;
	int a[4] = {0};
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	if (s.size() == 4)
		return 2;
	else if (s.size() == 3)
		return 2;
	else if (s.size() == 2)
	{
		sort(a, a + 4);
		if (a[0] == a[1])
			return 2;
		else
			return 1;
	}
	return 0;
}

int solve()
{
	int a[4] = {0}, cnt = 0;
	vector<bool> v(4, false);
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		v[i] = false;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (i != j and a[i] != a[j] and !v[i] and !v[j])
			{
				v[i] = true;
				v[j] = true;
				cnt++;
			}
		}
	}
	return cnt;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}


	return 0;
}