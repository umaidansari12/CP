#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct marks {
	int p, c, m;
};

bool cmp(marks a, marks b)
{
	if (a.p != b.p) return a.p < b.p;
	else if (a.p == b.p)
	{
		if (a.c == b.c)
		{
			return a.m < b.m;
		}
		return a.c > b.c;
	}
	return false;
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
		int n, p, c, m;
		cin >> n;
		vector<marks> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> p >> c >> m;
			s[i].p = p;
			s[i].c = c;
			s[i].m = m;
		}
		sort(s.begin(), s.end(), cmp);
		for (auto i : s)
		{
			cout << i.p << " " << i.c << " " << i.m << endl;
		}
	}


	return 0;
}