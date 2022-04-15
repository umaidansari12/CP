#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPermutationMap(string s1, string s2, int n, int m)
{
	if (n != m)
		return false;
	map<char, int> count;
	for (int i = 0; i < n; i++)
	{
		count[s1[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		count[s2[i]]--;
	}
	auto i = count.begin();
	while (i != count.end())
	{
		if (i->second != 0)
			return false;
		i++;
	}
	return true;
}

bool isPermutationSort(string s1, string s2, int n, int m)
{
	if (n != m)
		return false;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
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
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		if (isPermutationSort(s1, s2, n, m))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}