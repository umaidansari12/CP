#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		int count1 = 0, count14 = 0, count144 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				count1++;
				if ((i + 1) < n and s[i + 1] == '4') {
					count14++;
					if ((i + 2) < n and s[i + 2] == '4') {
						count144++;
					}
				}
			}
		}
		if ((count1 + count14 + count144) == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}