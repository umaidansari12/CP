#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				cnt++;
		int rem = (120 - n) + cnt;
		float per = (rem / (float)120) * 100;
		if (per >= 75)
			cout << "YES\n";
		else
			cout << "NO\n";
//		cout << per << endl;

	}


	return 0;
}