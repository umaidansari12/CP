#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> solve()
{
	int n;
	cin >> n;
	vector<string> s(n), t(n), res;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	// for (auto i : s)
	// 	cout << i << " ";
	// cout << endl;
	// for (auto i : t)
	// 	cout << i << " ";
	// cout << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << s[i].size() << " " << t[i].size() << endl;
		if (s[i].size() == t[i].size())
		{
			int count[26] = {0};
			int count1[26] = {0};
			for (auto ch : s[i])
			{
				count[ch - 'a']++;
			}
			for (auto ch : t[i])
			{
				count1[ch - 'a']++;
			}
			bool flag = true;
			for (int j = 0; j < 26; j++)
			{
				if (abs(count[j] - count1[j]) > 3)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				res.push_back("YES");
			else
				res.push_back("NO");
		}
		else
		{
			res.push_back("NO");
		}
	}
	return res;
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
		vector<string> r = solve();
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}