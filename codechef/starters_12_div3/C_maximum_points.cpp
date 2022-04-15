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
		vector<long long int> times(3, 0), marks(3, 0);
		for (int i = 0; i < 3; i++) {
			cin >> times[i];
		}
		for (int i = 0; i < 3; i++) {
			cin >> marks[i];
		}
		long long int ans = 0;
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				for (int k = 0; k <= 20; k++) {
					long long int time = i * times[0] + j * times[1] + k * times[2];
					if (time <= 240) {
						ans = max(ans, (long long int)( i * marks[0] + j * marks[1] + k * marks[2]));
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}