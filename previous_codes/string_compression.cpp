#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size(), count = 0;
		string s;
		for (int i = 0; i < n; i++)
		{
			count++;
			if (i + 1 >= n || chars[i] != chars[i + 1])
			{
				s += chars[i];
				if (count > 1)
				{
					if (count > 10)
					{
						string h;
						while (count > 0)
						{
							h += (to_string(count % 10));
							count /= 10;
						}
						int m = h.size();
						for (int j = m - 1; j >= 0; j--)
							s += h[j];
					}
					else
					{
						s += (to_string(count));
					}
				}

				count = 0;
			}
		}
		for (int i = 0; i < s.size(); i++)
			chars[i] = s[i];
		return s.size();


	}
};

void solve(string s1)
{
	int countConsecutives = 0, n = s1.size();
	/*map<char, int> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		m[s1[i]]++;
	}
	for (auto i : m)
	{
		s += (i.first);
		s += (to_string(i.second));
	}
	return s.size() < s1.size() ? s : s1;*/

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
		string s1, s2;
		cin >> s1;
		int n = s1.length(), cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] == s1[i + 1])
				cnt++;
			else
			{
				s2 += s1[i];
				s2 += to_string(cnt + 1);
				cnt = 0;
			}
		}
		if (s2.length() > s1.length())
			cout << s1 << endl;
		else
			cout << s2 << endl;

	}


	return 0;
}