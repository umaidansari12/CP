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
		int a[n] = {0};
		map<int, int> count;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			count[a[i]]++;
		}
		if (count[a[0]] >= 2 or a[0] == a[n - 1])
			cout << (n - 1) << endl;
		else
			cout << (-1) << endl;
	}


	return 0;
}