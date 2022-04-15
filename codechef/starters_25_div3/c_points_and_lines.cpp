#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Given n points of the form (xi, yi) on a 2 - D plane
// From each point you draw 2 lines one horizontal and one vertical
// Lines may overlap with each other.
// We need to find distinct lines formed on the plane

// Note :

// Two horizontal lines are said to be distinct if they pass through different y coordinates
// Two vertical lines are said to be distinct if they pass through different x coordinates

// 	the horizontal lines passing through same y coordinates are overlapping each other
// 	the vertical lines passing through same x coordinates are overlapping each other

/*Solution : to get the distinct horizontal lines we just need to count different y coordinates
to get the distinct vertical lines we just need to count different x coordinates*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n;
		set<int> X, Y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			X.insert(x);
			Y.insert(y);
		}
		cout << (X.size() + Y.size()) << endl;
	}


	return 0;
}