#include <bits/stdc++.h>

using namespace std;

/*
Learnings
	- not read question and given info properly
	- not spending much time on approach
	- not able to clearly go through test cases and think of more test cases
	- missing edge cases
		- float comparison
		- max_area comparison logic
		- equality case logic
*/

class Solution {
public:
	int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
		// take 2 variables max diagonal and max area, initialize as 0, if found greater than
		int _size = dimensions.size(), max_area = 0;
		float max_diagonal = 0.0;
		for (int i = 0; i < _size; i++) {
			float diagonal = sqrt(dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
			// cout << diagonal << "-";
			if (diagonal > max_diagonal) {
				max_area = (dimensions[i][0] * dimensions[i][1]);
				max_diagonal = diagonal;
			}
			else if (diagonal == max_diagonal) {
				max_area = max(max_area, dimensions[i][0] * dimensions[i][1]);
			}
		}
		return max_area;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> dimensions(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			cin >> dimensions[i][0] >> dimensions[i][1];
		}
		Solution ob = Solution();
		cout << ob.areaOfMaxDiagonal(dimensions) << endl;
	}
}

/*
5
2
9 3
8 6
2
3 4
4 3
4
2 6
5 1
3 10
8 4
3
10 3
5 9
8 3
7
6 5
8 6
2 10
8 1
9 2
3 5
3 5

*/