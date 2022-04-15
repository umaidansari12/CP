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
		string a;
		char b;
		cin >> a >> b;
		int n = a.size();
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (a[i] == b) {
				if (i % 2 == 0) {
					found = true;
				}
			}
		}

		if (found)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}