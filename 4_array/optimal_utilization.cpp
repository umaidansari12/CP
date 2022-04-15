#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Given 2 lists a and b. Each element is a pair of integers where the
  first integer represents the unique id and the second integer
  represents a value. Your task is to find an element from a and an
  element form b such that the sum of their values is less or equal
  to target and as close to target as possible. Return a list of ids
  of selected elements. If no pair is possible, return an empty
  list.

  4
3
1 2
2 4
3 6
1
1 2
7
4
1 3
2 5
3 7
4 10
4
1 2
2 3
3 4
4 5
10
3
1 8
2 15
3 9
3
1 8
2 11
3 12
20
3
1 8
2 7
3 14
3
1 5
2 10
3 14
20

  */


vector<pair<int, int>> optimalUtilizationBrute(vector<pair<int, int> > &a, vector<pair<int, int>> &b, int target) {
	vector<pair<int, int>> res;
	int n = a.size(), m = b.size(), diff = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int curr_sum = a[i].second + b[j].second;
			if (curr_sum <= target) {
				int curr_diff = (target - (curr_sum));
				if (curr_diff < diff) {
					res.clear();
					res.push_back({a[i].first, b[j].first});
					diff = curr_diff;
				}
				else if (curr_diff == diff) {
					res.push_back({a[i].first, b[j].first});
				}
			}

		}
	}
	return res;
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

vector<pair<int, int>> optimalUtilization(vector<pair<int, int> > &a, vector<pair<int, int>> &b, int target) {

	sort(a.begin(), a.end(), comp);
	sort(b.begin(), b.end(), comp);
	vector<pair<int, int>> res;
	int n = a.size(), m = b.size(), i = 0, j = m - 1, diff = INT_MAX;
	while (i<n and j >= 0) {
		int curr_sum = a[i].second + b[j].second;
		if (curr_sum <= target) {
			int curr_diff = target - curr_sum;
			if (curr_diff < diff) {
				res.clear();
				res.push_back({a[i].first, b[j].first});
				diff = curr_diff;
			}
			else if (curr_diff == diff) {
				res.push_back({a[i].first, b[j].first});
			}
			i++;
		}
		else if (curr_sum > target) {
			j--;
		}
	}

	return res;


}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		int m;
		cin >> m;
		vector<pair<int, int>> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i].first >> b[i].second;
		}
		int target;
		cin >> target;
		vector < pair<int, int>> result = optimalUtilization(a, b, target);
		for (auto i : result) {
			cout << i.first << " " << i.second << ":";
		}
		cout << endl;
	}


	return 0;
}