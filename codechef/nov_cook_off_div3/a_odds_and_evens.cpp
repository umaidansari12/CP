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
		int a, b;
		cin >> a >> b;
		if ((a + b) % 2 == 0)
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}


	return 0;
}

