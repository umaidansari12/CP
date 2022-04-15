#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string alpha = "abcdefghijklmnopqrstuvwxyzabcedfghijklmnopqrstuvwxyz";
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		int k;
		cin >> k;
		k %= 26;
		for (int i = 0; i < s.size(); i++)
		{
			int idx = s[i] - 'a';
			if (idx - k <= 0)
			{
				idx += 26;
			}
			cout << alpha[idx - k] << endl;
		}
	}

	return 0;
}