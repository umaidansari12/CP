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
		string je, s;
		cin >> je >> s;
		/*auto i = std::unique(j.begin(), j.end());
		j.resize(std::distance(j.begin(), i));
		int c = 0;
		for (int m = 0; m < j.size(); m++)
		{
			for (int k = 0; k < s.size(); k++)
			{
				if (j[m] == s[k])
					c++;
			}
		}*/
		vector<int> cnt(256, 0);
		bool vis[256] = {false};
		for (int i = 0; i < s.size(); i++)
		{
			cnt[s[i]]++;
		}
		int c = 0;
		for (int j = 0; j < je.size(); j++)
		{
			if (!vis[je[j]])
			{
				c += cnt[je[j]];
				vis[je[j]] = true;
			}
		}
		cout << c << endl;
	}


	return 0;
}