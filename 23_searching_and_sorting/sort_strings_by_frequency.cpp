#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		string s;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			m[s]++;
		}

		vector<pair<string, int>> arr;
		for (auto i : m) {
			arr.push_back({i.first, i.second});
		}

		sort(arr.begin(), arr.end(), [](pair<string, int> a, pair<string, int> b) {
			if (a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[i].second; j++) {
				cout << arr[i].first << " ";
			}
		}

		cout << endl;

	}


	return 0;
}