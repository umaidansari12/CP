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
		int x;
		cin >> x;
		if (x >= 1 and x < 100) {
			cout << "Easy\n";
		}
		else if (x >= 100 and x < 200) {
			cout << "Medium\n";
		}
		else if (x >= 200 and x <= 300) {
			cout << "Hard\n";
		}
	}


	return 0;
}