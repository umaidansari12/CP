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
		int n;
		cin >> n;
		for (int i = 1; i <= 12; i++) {
			cout << n << " * " << i << " = " << n*i << "\n";
		}
	}


	return 0;
}