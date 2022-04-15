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
		int ans = -1;
		for (int i = s.size(); i >= 0; i--)
		{
			if (s[i] == '1')
			{
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}


	return 0;
}