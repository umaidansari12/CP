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
		int n;
		cin >> n;
		map<string, int> m;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			m[s]++;
		}
		if (n == 1)
		{
			cout << s << endl;
		}
		else
		{
			int j = 0;
			string r = "";
			while (j <= n)
			{
				auto i = m.begin();
				string s1 = i->first;
				int n1 = s1.size();
				string s2 = s1.substr(0, n1 - j);
				//cout << s2 << endl;
				//i++;
				while (i != m.end())
				{
					s1 = i->first;
					if (s1[0] != s2[0])
						break;
					if (s1.find(s2) == std::string::npos)
						break;
					i++;
				}
				if (i == m.end())
				{
					r = s2;
					break;
				}
				j++;
			}
			if (r == "")
				cout << -1 << endl;
			else
				cout << r << endl;
		}


		/*while (i != m.end())
		{
			cout << i->first << " " << i->second << endl;
			i++;
		}*/
	}



	return 0;
}

class Solution {
public:
	string solve(string s1, string s2)
	{
		string res = "";
		for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++)
		{
			if (s1[i] != s2[j])
				break;
			res += s1[i];
		}
		return res;
	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		int n = strs.size();
		string pre = strs[0];
		for (int i = 1; i < n; i++)
		{
			pre = solve(pre, strs[i]);
		}
		return pre;
	}
};