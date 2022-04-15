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
		int n, x, count = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x >= 10 and x <= 60)
				count++;
		}
		cout << count << endl;

	}


	return 0;
}