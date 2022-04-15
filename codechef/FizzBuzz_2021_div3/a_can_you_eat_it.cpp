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
		long long int n, k;
		cin >> n >> k;
		if ((n % k) == 0)
			cout << (n / k) << endl;
		else
			cout << -1 << endl;
	}


	return 0;
}