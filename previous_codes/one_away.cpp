#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool oneAwayReplace(string s1, string s2)
{
	bool f = false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			if (f)
				return false;
			f = true;
		}
	}
	return true;
}

bool oneAwayInsert(string s1, string s2)
{
	int i1 = 0, i2 = 0, n = s1.size(), m = s2.size();
	while (i2 < m && i1 < n)
	{
		if (s1[i1] != s2[i2])
		{
			if (i1 != i2)
				return false;
			i2++;
		}
		else
		{
			i1++;
			i2++;
		}
	}
	return true;
}

bool oneAway(string s1, string s2)
{
	if (s1.size() == s2.size())
		return oneAwayReplace(s1, s2);
	else if (s1.size() + 1 == s2.size())
		return oneAwayInsert(s1, s2);
	else if (s1.size() - 1 == s2.size())
		return oneAwayInsert(s2, s1);
	return true;
}


bool oneEditAway(string s1, string s2)
{
	int n = s1.size(), m = s2.size();
	if (abs(n - m) > 1)
		return false;
	string f = s1.size() < s2.size() ? s1 : s2;
	string s = s1.size() < s2.size() ? s2 : s1;
	int i1 = 0, i2 = 0;
	bool foundDifference = false;
	while (i2 < s.size() && i1 < f.size())
	{
		if (f[i1] != s[i2])
		{
			if (foundDifference)
				return false;
			foundDifference = true;
			if (f.size() == s.size())
			{
				i1++;
			}
		}
		else
		{
			i1++;
		}
		i2++;
	}
	return true;
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
		cin.ignore();
		cin >> s2;
		if (oneAway(s1, s2))
			cout << "Yes\n";
		else
			cout << "No\n";
		/*int n = s1.size(), m = s2.size();
		if (abs(n - m) > 1)
		{
			cout << "no" << endl;
			continue;
		}
		map<char, int> count;
		int distance = 0;
		for (int i = 0; i < n; i++)
		{
			count[s1[i]]++;
		}
		for (int i = 0; i < m; i++)
		{
			count[s2[i]]--;
		}
		auto i = count.begin();
		while (i != count.end())
		{
			if (i->second % 2 == 1)
				distance++;
			i++;
		}
		if (distance == 1)
			cout << "yes" << endl;
		else if (distance == 0)
			cout << "no" << endl;
		else
			cout << "no" << endl;*/
	}

	return 0;
}