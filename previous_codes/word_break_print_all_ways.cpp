#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dictContains(vector<string> &dict, string &prefix)
{
	for (int i = 0; i < dict.size(); i++)

	{	if (dict[i].compare(prefix) == 0)
			return true;
	}
	return false;
}
void wordBreak(string s, vector<string>&dict, int n, string res)
{
	for (int i = 1; i <= n; i++)
	{
		string prefix = s.substr(0, i);
		if (dictContains(dict, prefix))
		{
			if (i == n)
			{
				res += prefix;
				cout << "(" << res << ")";
				return;
			}
			wordBreak(s.substr(i, n - i), dict, n - i, res + prefix + " ");
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<string> dict(n);
		for (int i = 0; i < n; i++)
			cin >> dict[i];
		string s, res;
		cin >> s;
		wordBreak(s, dict, s.size(), res);
		cout << endl;
	}


	return 0;
}