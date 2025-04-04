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
		long long int z, x, securities = 0;
		cin >> z;
		vector<pair<long long int, long long int>> a;
		while (cin >> x) {
			idx++;
			a.push_back({x, idx});
		}
		for (int i = 0; i < a.size(); i++) {
			if (((i + 1)*a[i]) <= z) {
				securities += (i + 1);
				z -= ((i + 1) * a[i]);
			}
			else {

			}
		}
		cout << securities << endl;
	}


	return 0;
}