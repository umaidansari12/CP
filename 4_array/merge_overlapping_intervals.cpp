#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>> overlappedIntervalBrute(vector<vector<int>>& intervals) {
		// Code here
		int n = intervals.size();
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
			if (a[0] == b[0])
				return a[1] < b[1];
			return a[0] < b[0];
		});
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (intervals[i][0] != -1 and intervals[j][0] != -1 and intervals[i][1] >= intervals[j][0])
				{
					intervals[i][1] = max(intervals[i][1], intervals[j][1]);
					intervals[j][0] = -1;
					intervals[j][1] = -1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (intervals[i][0] != -1)
				res.push_back(intervals[i]);
		}
		return res;
	}

	vector<vector<int>> mergeBrute(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
			if (a[0] == b[0])
				return a[1] < b[1];
			return a[0] < b[0];
		});

		vector<vector<int>> merged;
		int n = intervals.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (intervals[i][0] != -1 and intervals[j][0] != -1 and intervals[i][1] >= intervals[j][0]) {
					intervals[i][1] = max(intervals[i][1], intervals[j][1]);
					intervals[j][0] = -1;
					intervals[j][1] = -1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (intervals[i][0] != -1)
				merged.push_back(intervals[i]);
		}
		return merged;

	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
			if (a[0] == b[0])
				return a[1] < b[1];
			return a[0] < b[0];
		});

		vector<vector<int>> merged;
		vector<int> temp = intervals[0];
		int n = intervals.size();
		for (int i = 0; i < n; i++) {
			if (temp[1] >= intervals[i][0]) {
				temp[1] = max(intervals[i][1], temp[1]);
			}
			else
			{
				merged.push_back(temp);
				temp[0] = intervals[i][0];
				temp[1] = intervals[i][1];
			}
		}
		merged.push_back(temp);
		return merged;

	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for (auto i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends