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
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int sum = a + b;
		if (sum < 3)
			cout << 1 << endl;
		else if (sum >= 3 and sum <= 10)
			cout << 2 << endl;
		else if (sum >= 11 and sum <= 60)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}


	return 0;
}