#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int n = s.size();
		sort(s.begin(), s.end());
		vector<int> cnt(26, 0);
		for (int i = 0; i < n; i++)
		{
			cnt[s[i] - 'a']++;
		}
		int c = 0, ans = 0;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] % 2 == 1)
			{
				if (c == 0)
					c += 1;
				else if (c == 1)
				{
					ans += (cnt[i]);
				}
			}
		}
		cout << ans << endl;
	}



	return 0;
}