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
		cout << 1 << " ";
		long long int power = 1;
		for (int i = 0; i < n; i++) {
			cout << (long long int)power << " ";
			power *= 2;
		}
		cout << endl;
	}


	return 0;
}