#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string extractStringAtGivenKey(string s, int key)
{
	stringstream ss(s);
	string token;
	int i = 0;
	while (getline(ss, token, ' '))
	{
		if (i == key - 1)
			return token;
		i++;
	}
	return token;

}

int convertToInt(string s) {

	int ans = 0;
	int p = 1;

	for (int i = s.length() - 1; i >= 0; i--) {
		ans += ((s[i] - '0') * p);
		p = p * 10;
	}
	return ans;
}

bool lexicoCompare(pair<string, string> &a, pair<string, string> &b)
{
	return a.second < b.second;
}

bool numericCompare(pair<string, string> &a, pair<string, string> &b)
{
	return stoll(a.second) < stoll(b.second);
}

string extractStringAtGivenKey1(string s, int key)
{
	char* token = strtok((char*)s.c_str(), " ");
	while (key > 1)
	{
		token = strtok(NULL, " ");
		key--;
	}
	return string(token);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, key;
		cin >> n;
		cin.ignore();
		vector<string> v(n);
		for (int i = 0; i < n; i++)
		{
			getline(cin, v[i]);
		}
		string reversal, ordering;
		cin >> key >> reversal >> ordering;
		vector<pair<string, string>> vp(n);
		for (int i = 0; i < n; i++)
		{
			vp[i] = {v[i], extractStringAtGivenKey(v[i], key)};
		}
		if (ordering == "numeric")
		{
			sort(vp.begin(), vp.end(), numericCompare);
		}
		else
		{
			sort(vp.begin(), vp.end(), lexicoCompare);
		}
		if (reversal == "true")
			reverse(vp.begin(), vp.end());
		for (auto i : vp)
			cout << i.first << endl; //<< ":" << i.second << endl;
	}

	return 0;
}