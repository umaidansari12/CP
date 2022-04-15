#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin>>t;
	while (t--) {
		int n, x, even = 0, odd = 0, pos = 0, neg = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if ((x % 2) == 0) {
				even++;
			}
			else {
				odd++;
			}

			if (x > 0) {
				pos++;
			}
			else if (x < 0) {
				neg++;
			}
		}
		cout << "Even: " << even << "\nOdd: " << odd << "\nPositive: " << pos << "\nNegative: " << neg << endl;
	}


	return 0;
}