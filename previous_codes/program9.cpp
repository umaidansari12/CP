#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string ArrayChallenge(string strArr[], int arrLength) {
	int x, y;
	vector<pair<int, int>> a;
	for (int i = 0; i < 4; i++) {
		x = strArr[i][0] - '0';
		y = strArr[i][1] - '0';
		a.push_back({x, y});
	}
	x = 0;
	y = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i].first == a[j].first) {
				x = max(x, abs(a[i].second - a[j].second));
			}
			if (a[i].second == a[j].second) {
				y = max(y, abs(a[i].first - a[j].first));
			}
		}
	}
	return to_string(x * y);

}

int main()
{
	int t;
	cin >> t;
	while (t--) {


	}
	return 0;
}



