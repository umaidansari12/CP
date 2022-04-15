#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(string s1, string s2)
{
	if (s1.size() != s2.size())
		return false;
	s1 += s1;
	return s1.find(s2) != std::string::npos;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s1, s2;
		cin >> s1;
		cin.ignore();
		cin >> s2;
		if (solve(s1, s2))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}