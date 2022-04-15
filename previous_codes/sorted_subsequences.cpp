#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool comp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

void subsequence(string s, string o, vector<string> &v) {
	//base case
	if (s.size() == 0) {
		v.push_back(o);
		return;
	}

	//rec case
	char ch = s[0];
	string reduced_input = s.substr(1);

	//includes
	subsequence(reduced_input, o + ch, v);

	//excludes
	subsequence(reduced_input, o , v);
}

void sortedSubsequences(string s, string res, int i, int n, vector<string>&r)
{
	if (i == n)
	{
		r.push_back(res);
		return;
	}

	sortedSubsequences(s, res, i + 1, n, r);
	sortedSubsequences(s, res + s[i], i + 1, n, r);
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
		string s1;
		cin >> s1;
		int n = s1.size();
		vector<string> r;
		string res;
		sortedSubsequences(s1, res, 0, n, r);
		/*
		Bitmasking Approach
		r.push_back("");
		for (int i = 1; i < (1 << n); i++)
		{
			string s;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
					s += s1[j];
			}
			r.push_back(s);
		}*/
		sort(r.begin(), r.end(), comp);
		for (auto i : r)
			cout << i << ",";
		cout << endl;
	}

	return 0;
}