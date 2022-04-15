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
		int n, a;
		cin >> n >> a;
		cout << int(sqrt(n))*a << '\n';
	}


	return 0;
}