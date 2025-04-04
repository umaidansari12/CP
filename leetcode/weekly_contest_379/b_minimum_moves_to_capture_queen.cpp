#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
		int directions[4][4] = {{ -1, -1}, { -1, +1}, { +1, +1}, { +1, -1}};
		int min_moves = 2;
		for (int i = 0; i < 4; i++) {
			int bishop_x = c, bishop_y = d;
			while (bishop_x >= 1 and bishop_x <= 8 and bishop_y >= 1 and bishop_y <= 8) {
				bishop_x += directions[i][0];
				bishop_y += directions[i][1];
				if (bishop_x == a and bishop_y == b) {
					break;
				}
				if (bishop_x == e and bishop_y == f) {
					cout << "b\n";
					min_moves = 1;
				}
			}
		}
		if (a == e and a != c) {
			cout << "rv\n";
			return 1;
		}
		if (b == f and b != d) {
			cout << "rh\n";
			return 1;
		}
		return min_moves;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		Solution ob = Solution();
		cout << ob.minMovesToCaptureTheQueen(a, b, c, d, e, f) << endl;
	}
}