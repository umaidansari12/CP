#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printSubsequence(string s, int idx, int n, string r)
{
	if (idx == n)
	{
		cout << r << " ";
		return;
	}
	printSubsequence(s, idx + 1, n, r);
	printSubsequence(s, idx + 1, n, r + s[idx]);

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
		printSubsequence(s, 0, s.size(), "");
	}


	return 0;
}