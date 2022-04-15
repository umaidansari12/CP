#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n;
	string s;
	cin >> s;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int count[26] = {0};
		for (int i = l; i <= r; i++)
			count[s[i] - 'a']++;
		string s1;
		for (int i = 0; i < 26; i++)
		{
			if (count[i] > 0)
			{
				s1 += string(count[i], i + 'a');
				count[i]--;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (count[i] > 0)
			{
				s1 += string(count[i], i + 'a');
				count[i]--;
			}
		}
		if (s1 != "")
		{
			int c = 0;
			for (int i = l; i <= r; i++)
			{
				s[i] = s1[c++];
			}
		}
	}
	cout << s << endl;


	return 0;
}