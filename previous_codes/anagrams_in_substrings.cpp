#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> getHash(string s, int i, int j)
{
	vector<int> freq(26, 0);
	for (int k = i; k <= j; k++)
		freq[s[k] - 'a']++;
	return freq;
}

int anagramsInSubstrings(string s) {
	//Generate the substring
	//Hash the substring with their frequency hash value
	map<vector<int>, int> m;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			vector<int> h = getHash(s, i, j);
			m[h]++;
		}
	}
	int ans = 0;
	for (auto i : m)
	{
		int freq = i.second;
		if (freq >= 2)
			ans += ((freq * (freq - 1))) / 2;
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << anagramsInSubstrings(s) << endl;

	}


	return 0;
}