#include <bits/stdc++.h>

using namespace std;

/*
Q - Why greedy fails?

I - 10 50 1
O - 10 100 11
If we try to pick 50 first, max out of day 0, then pick 11, on day 1, as we can't pick same activity on the next day, so total will be 50 + 11 = 61
But if we use dp, and check all possible ways, since we know all ways beforehand, we can pick 10 on day 0, and then on day 1, we will pick 100, so the total will 10 + 100 = 110

So as we can see we need to try all possible stuffs, then we will use recursion
and to apply recursion we need to
- Represent our problem in terms of index
- Do stuffs on index
- Find max merit point
*/

// int ninjaTrainingHelper(int row, int col, int n, vector<vector<int>> &arr) {
// 	if (row == n)
// 		return 0;
// 	int answer = 0;
// 	for (int i = 0; i < 3; i++) {
// 		if (i != col)
// 			answer = max(answer, arr[row][col] + ninjaTrainingHelper(row + 1, i, n, arr));
// 	}
// 	return answer;
// }

// int ninjaTraining(int n, vector<vector<int>> &points) {
// 	cout << "------\n";
// 	int answer = 0;
// 	for (int i = 0; i < 3; i++) {
// 		answer = max(answer, ninjaTrainingHelper(0, i, n, points));
// 	}
// 	return answer;
// }

// This is wrong debug
// int ninjaTrainingHelper(int n, vector<vector<int>> &arr, int row = 0, int col = 0) {
// 	if (row == n)
// 		return 0;
// 	int answer = 0;
// 	cout << "----" << row << "----" << col << "\n";
// 	for (int i = 0; i < 3; i++) {
// 		if (row == 0) {
// 			answer = max(answer, arr[row][i] + ninjaTrainingHelper(n, arr, row + 1, i));
// 			cout << "*" << answer << "*";
// 		}
// 		else if (i != col) {
// 			answer = max(answer, arr[row][col] + ninjaTrainingHelper(n, arr, row + 1, i));
// 			cout << "-" << answer << "-";
// 		}
// 	}
// 	cout << endl;
// 	return answer;
// }

// TC - O(3^n)
// SC - O(n)

int ninjaTraining(int n, vector<vector<int>> &points, int last = 3) {
	// base case
	// if we've reached at the last row, then we've to pick the max option if it is not performed earlier
	if (n == 0) {
		int answer = 0;
		for (int i = 0; i < 3; i++) {
			if (i != last)
				answer = max(answer, points[n][i]);
		}
		return answer;
	}
	int answer = 0;
	// We've to pick every activity except those which was performed earlier
	for (int i = 0; i < 3; i++) {
		if (i != last) {
			answer = max(answer, points[n][i] + ninjaTraining(n - 1, points, i));
		}
	}

	return answer;
}

// TC - O(N*4)x3
// N*4 - is the number of states  - 4 we're considering to incorporate last=3, stage
// 3 is the for loop which we're running in every state
// SC - O(N) + O(Nx4) - at max N levels deep + dp array
// We're taking Nx4 size array so as to include the case wherein we're performing all 3 activities and taking max out of it, suppose only 1 day is there so you will perform maximum of all 3
int ninjaTraining(int day, vector<vector<int>> &points, vector<vector<int>> &dp, int last = 3) {
	// base case
	// if we've reached at the last row, then we've to pick the max option if it is not performed earlier
	if (day == 0) {
		int answer = 0;
		for (int task = 0; task < 3; task++) {
			if (task != last)
				answer = max(answer, points[day][task]);
		}
		return dp[day][last] = answer;
	}
	// if (last != 3 and dp[n][last] != -1) {
	// 	return dp[n][last];
	// }
	if (dp[day][last] != -1) {
		return dp[day][last];
	}

	int answer = 0;
	// We've to pick every activity except those which was performed earlier
	for (int task = 0; task < 3; task++) {
		if (task != last) {
			answer = max(answer, points[day][task] + ninjaTraining(day - 1, points, dp, task));
		}
	}

	return dp[day][last] = answer;
}

// TC - O(Nx4x3)
// SC - O(Nx4)
int ninjaTrainingTabu(int n, vector<vector<int>> &points) {
	// vector<vector<int>> dp(n, vector<int>(4, -1));
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		int answer = 0;
	// 		for (int k = 0; k < 3; k++) {
	// 			if (i == 0) {
	// 				if (k != j) {
	// 					answer = max(answer, points[i][k]);
	// 				}
	// 			}
	// 			else {
	// 				if (k != j) {
	// 					answer = max(answer, points[i][k] + dp[i - 1][k]);
	// 				}
	// 			}

	// 		}
	// 		dp[i][j] = answer;
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// // return dp[n - 1][2];
	// return dp[n - 1][2];
	int last = 4;
	vector<vector<int>> dp(n, vector<int>(last, -1));
	//n - day no. of task
	//last - represent last task which we've perfomed, if we're on day 0, so we will perform each task to get maximum merit point, so passing last =3,will mean last task which was performed is 3, which is not in our list, so we can perform all of the tasks to get maximum
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
	// base case
	// last 0 - don't perform task 0, as it was last, so take out maximum of 1,2, similarly do for task 1 and task 2
	// last 3 - means we're starting and we need to perform every task and find max merit point
	for (int day = 1; day < n; day++) {
		for (int last = 0; last < 4; last++) {
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					int point = points[day][task] + dp[day - 1][task];
					dp[day][last] = max(dp[day][last], point);
				}
			}
		}
	}
	return dp[n - 1][last - 1];
}

int ninjaTrainingSpaceOptimize(int n, vector<vector<int>> &points) {
	// instead of declaring a nx4 array, we will need only 4 size array as calculation is based on last calculated state
	// we first calculated the current state, then use it for next state calculation, now current state is changed to next state as calculation is done
	vector<int> prev(4, 0);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day = 1; day < n; day++) {
		vector<int> temp(4, 0);
		for (int last = 0; last < 4; last++) {
			for (int task = 0; task < 3; task++) {
				if (task != last)
					temp[last] = max(temp[last], points[day][task] + prev[task]);
			}
		}
		// for (int i = 0; i < 4; i++)
		// cout << temp[i] << " ";
		// cout << endl;
		prev = temp;
	}
	return prev[3];
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(3, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
				// cout << arr[i][j] << " ";
			}
			// cout << endl;
		}

		// vector<vector<int>> dp(n, vector<int>(3, -1));
		vector<vector<int>> dp(n, vector<int>(4, -1));
		cout << ninjaTraining(n - 1, arr) << endl;
		cout << ninjaTraining(n - 1, arr, dp) << endl;
		cout << ninjaTrainingTabu(n, arr) << endl;
		cout << ninjaTrainingSpaceOptimize(n, arr) << endl;
	}
}

/*
I -
3
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
4
2 1 3
3 4 6
10 1 6
8 3 7

O -
11
210
25
*/