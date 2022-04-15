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
		int x;
		cin >> x;

		bool isPrime = true;
		for (int i = 2; i < x; i++) {
			if (x % i == 0)
				isPrime = false;
		}
		if (x >= 1 and isPrime)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}