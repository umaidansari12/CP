#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve()
{
	long long int n, k, cnt = 0, ans = 0;
	cin >> n >> k;
	string s;
	cin.ignore();
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
		{
			//cout << cnt << " ";
			cnt++;
			ans = max(ans, cnt);
			//cout << cnt << endl;
		}
		else
		{
			cnt = 0;
		}
	}
	if (ans >= k)
		return true;
	else
		return false;
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

		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}