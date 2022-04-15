#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
		{
			return a[0] < b[0];
		});
		vector<vector<int>> res;
		vector<vector<int>> current_interval;
		current_interval.push_back(intervals[0]);
		res.push_back(intervals[0]);
		for (auto interval : intervals)
		{
			int current_begin = current_interval[0][0];
			int current_end = current_interval[0][1];
			int next_begin = interval[0];
			int next_end = interval[1];
			if (current_end >= next_begin)
				current_interval[0][1] = max(current_end, next_end);
			else
			{
				current_interval[0][0] = interval[0];
				current_interval[0][1] = interval[1];
				res.push_back(current_interval[0]);
			}
		}

		return res;
	}
};

class Solution1 {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1)
			return intervals;
		int n = intervals.size();
		sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
		{
			return a[0] < b[0];
		});
		vector<vector<int>> res;
		res.push_back(intervals[0]);
		for (int i = 1; i < n; i++)
		{
			if (res.back()[1] < intervals[i][0])
			{
				res.push_back(intervals[i]);
			}
			else
			{
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		}
		return res;

	}
};


vector<pair<int, int>> mergeOverlappingSubintervals(vector<pair<int, int>>&intervals, int n)
{
	if (intervals.size() <= 1)
		return intervals;
	sort(intervals.begin(), intervals.end(), [](const pair<int, int>&a, const pair<int, int>&b)
	{
		return a.first < b.first;
	});
	vector<pair<int, int>> res;
	res.push_back(make_pair(intervals[0].first, intervals[0].second));
	for (int i = 1; i < n; i++)
	{
		if (res.back().second < intervals[i].first)
			res.push_back(make_pair(intervals[i].first, intervals[i].second));
		else
			res.back().second = max(res.back().second, intervals[i].second);
	}
	return res;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> intervals(n);
		for (int i = 0; i < n; i++)
		{
			cin >> intervals[i].first;
			cin >> intervals[i].second;
		}
		vector<pair<int, int>> res = mergeOverlappingSubintervals(intervals, n);
		for (auto& pair : res)
		{
			cout << pair.first << " " << pair.second << " ";
		}
		cout << endl;
	}


	return 0;
}