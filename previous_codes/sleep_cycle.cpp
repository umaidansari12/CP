#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve()
{
	long long h;
	int l;
	cin >> l >> h;
	string s;
	cin >> s;
	bool answer = false;
	int count = 0;
	int i = 0;
	while (i < l)
	{
		if (s[i] == '1')
		{
			i++;
			continue;
		}
		else if (s[i] == '0')
		{
			count = 0;
			while (i  < l and s[i] == '0')
			{
				i++;
				count++;
			}
			//cout << count << " " << h << endl;
			if (count < h)
			{
				h = 2 * (h - count);
				//count = 0;
				answer = false;
			}
			else if (count >= h)
			{
				//count = 0;
				answer = true;
			}
			//cout << answer << endl;
		}
	}
	//cout << answer << endl;
	return count < h ? false : true;
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
			cout << "Yes\n";
		else
			cout << "No\n";
	}


	return 0;
}