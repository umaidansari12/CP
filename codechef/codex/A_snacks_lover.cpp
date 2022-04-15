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
		int n, k, j, cost = 0;
		cin >> n >> k >> j;
		int a[n] = {0};
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == (j - 1))
				cost += a[i];
			else
				s.insert(a[i]);
		}
		k--;
		auto iter = s.begin();
		while (k--)
		{
			cost += *iter;
			iter++;
		}
		cout << cost << endl;
	}


	return 0;
}