#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (t--) {
		int a[3] = {0};
		for (int i = 0; i < 3; i++)
			cin >> a[i];
		sort(a, a + n);
		cout << a[1] << endl;

	}


	return 0;
}
