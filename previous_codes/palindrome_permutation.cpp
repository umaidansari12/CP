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
		map<char, int> count;
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i]]++;
		}
		auto i = count.begin();
		int f = 0, flag = 0;
		while (i != count.end())
		{
			if (i->second % 2 == 1)
			{
				if (f == 1)
				{
					flag = 1;
					break;
				}
				f = 1;
			}
			i++;
		}
		if (flag)
			cout << "No\n";
		else
			cout << "Yes\n";
	}


	return 0;
}