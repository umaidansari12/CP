#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	string s1, s2;
	cin >> s1;
	cin.ignore();
	cin >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		int a1 = tolower(s1[i]);
		int a2 = tolower(s2[i]);
		if (a1 == a2)
			continue;
		else if (a1 < a2)
			return -1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << solve() << endl;

	return 0;
}