#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		// auto i = s.find("LR");
		// while (!s.empty() and i != string::npos) {
		// 	s.erase(i, 2);
		// 	i = s.find("LR");
		// }
		// if (s.empty())
		// 	cout << "NO\n";
		// else
		// 	cout << "YES\n";
		//cout << s << endl;
		bool ok = false;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				ok = true;
				break;
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}