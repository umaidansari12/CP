#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		double  points_a = 1 * X + 0.5 * Y + 0 * Z;
		double points_b =  0 * X + 0.5 * Y + 1 * Z;
		int remaining_games = 4 - (X + Y + Z);
		points_a += double(remaining_games);
		// cout << points_a << "-" << points_b << endl;
		if (points_a > points_b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

/*

Input :
4
1 1 0
2 0 2
0 1 1
0 2 1

Output :

YES
NO
YES
NO



*/