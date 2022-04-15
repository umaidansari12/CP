#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//O(n2)
bool isUniqueBrute(string s, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
				return false;
		}
	}
	return true;
}

bool isUniqueMap(string s, int n)
{
	map<char, int> count;
	for (int i = 0; i < n; i++)
	{
		if (count[s[i]] == 1)
			return false;
		count[s[i]]++;
	}
	return true;
}

bool isUniqueBool(string s, int n)
{
	vector<bool> present(256, false);
	for (int i = 0; i < n; i++)
	{
		if (present[s[i]] == true)
			return false;
		present[s[i]] = true;
	}
	return true;
}

bool isUniqueSort(string s, int n)
{
	sort(s.begin(), s.end());
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
			return false;
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
		string s;
		cin >> s;
		int n = s.size();
		if (isUniqueBrute(s, n))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}



	return 0;
}