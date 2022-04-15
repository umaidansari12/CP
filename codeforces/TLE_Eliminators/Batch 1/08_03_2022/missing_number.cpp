#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	int a[n + 1] = {0};
	for (int i = 0; i < (n - 1); i++) {
		cin >> x;
		a[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			cout << i << endl;
			break;
		}
	}


	return 0;
}