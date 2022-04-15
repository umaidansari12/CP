#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void findingSubsets(int i, string s, string r, vector<string>&res)
{
	if (i == s.size())
	{
		res.push_back(r);
		return ;
	}

	findingSubsets(i + 1, s, r + s[i], res);
	findingSubsets(i + 1, s, r, res);
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
		vector<string> r;
		findingSubsets(0, s, "", r);
		//sort(r.begin(), r.end());
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}