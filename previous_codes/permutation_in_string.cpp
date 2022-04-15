#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool permutationInString(string s1, string s2, int n, int m)
{

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
		cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		cout << permutationInString(s1, s2, n, m) << endl;
	}

	return 0;
}