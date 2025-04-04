#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		int min_diff = INT_MAX, ans = -1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				int perimeter = 2 * (i + j);
				int diff = abs(perimeter - K);
				min_diff = min(diff, min_diff);
			}
		}
		cout << min_diff << endl;
	}
}

/*
Input -
4
5 5 12
3 4 5
2 1 9
34 45 1

Output -
0
1
3
3

*/