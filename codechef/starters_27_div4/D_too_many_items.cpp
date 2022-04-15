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
		if (n % 10 == 0)
			cout << n / 10 << endl;
		else
			cout << (n / 10) + 1 << endl;
	}

	return 0;
}