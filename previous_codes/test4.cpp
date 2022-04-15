#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(string s, int i, string r, string &prev, int &count)
{
	if (i == s.size())
	{
		if (r > prev)
		{
			prev = r;
			count++;
			cout << r << ' ';
		}
		return;
	}
	for (int j = i; j < s.size(); j++)
	{
		solve(s, i + 1, r + r.substr(i, j - i + 1), prev, count);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		string r, prev;
		int count = 0;
		solve(s, 0, r, prev, count);
		cout << count << endl;
	}



	return 0;
}