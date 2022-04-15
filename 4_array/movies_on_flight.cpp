#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
3
7
90 85 75 60 120 150 125
250
7
90 85 75 60 155 150 125
250
9
90 85 75 60 120 110 110 150 125
250
*/

pair<int, int> moviesOnFlightBrute(vector<pair<int, int>> &a, int n, int duration) {
	pair<int, int> result;
	int diff = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int curr_duration = a[i].first + a[j].first;
			if (curr_duration <= duration) {
				int curr_diff = duration - curr_duration;
				if (curr_diff < diff) {
					result.first = a[i].second;
					result.second = a[j].second;
					diff = curr_diff;
				}

			}
		}
	}
	return result;
}

pair<int, int> moviesOnFlight(vector<pair<int, int>> &a, int n, int duration) {
	sort(a.begin(), a.end());
	int i = 0, j = n - 1, diff = INT_MAX;
	pair<int, int> result;
	while (i < j) {
		int curr_duration = a[i].first + a[j].first;
		if (curr_duration <= duration) {
			int curr_diff = duration - curr_duration;
			if (curr_diff < diff) {
				result.first = a[i].second;
				result.second = a[j].second;
				diff = curr_diff;
			}
			i++;
		}
		else
			j--;
	}
	return result;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x, duration;
		cin >> n;
		vector<pair<int, int> > a;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.push_back({x, i});
		}
		cin >> duration;
		duration -= 30;
		pair<int, int> result = moviesOnFlight(a, n, duration);
		cout << result.first << " " << result.second << endl;
	}


	return 0;
}