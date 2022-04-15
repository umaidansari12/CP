#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--) {
			cout << " ";
		}
		for (int k = (2 * i) - 1; k > 0; k--) {
			cout << "*";
		}
		cout << "\n";

	}

	return 0;
}