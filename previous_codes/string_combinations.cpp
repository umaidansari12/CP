#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string getString(string s, string b)
{
	string o;
	for (int i = 0; i < s.size(); i++)
	{
		if (b[i] == '1')
			o += (s[i]);
	}
	return o;
}

string getBinaryString(int i, int n)
{
	string s;
	int c = 0;
	while (i > 0)
	{
		s = s + to_string(i % 2);
		i /= 2;
		c++;
	}
	while (c < n)
	{
		s += '0';
		c++;
	}
	reverse(s.begin(), s.end());
	return s;
}

vector<string> stringCombinations(string s, int n)
{
	vector<string> r;
	if (n == 0)
		return r;
	for (int i = 1; i <= pow(2, n) - 1; i++)
	{
		string binarystring = getBinaryString(i, n);
		//cout << binarystring << endl;
		string combination = getString(s, binarystring);
		r.push_back(combination);
		if (r.size() == (pow(2, n) - 1))
			return r;
	}
	return r;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		int n = s.size();
		vector<string> r = stringCombinations(s, n);
		sort(r.begin(), r.end());
		// for (int i = 0; i < r.size(); i++)
		// {
		// 	sort(r[i].begin(), r[i].end());
		// }
		for (auto i : r)
			cout << i << endl;
		cout << endl;

	}



	return 0;
}