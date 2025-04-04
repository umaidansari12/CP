#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
		int n = apple.size(), m = capacity.size();
		long long int apple_sum = 0;
		for (int i = 0; i < n; i++)
			apple_sum += apple[i];
		sort(capacity.begin(), capacity.end(), greater<int>());

		for (int i = 0; i < m; i++) {
			apple_sum -= (capacity[i]);
			if (apple_sum <= 0)
				return i + 1;
		}
		return m;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> apple(n, 0), capacity(m, 0);
		for (int i = 0; i < n; i++)
			cin >> apple[i];
		for (int j = 0; j < m; j++)
			cin >> capacity[j];
		Solution ob = Solution();
		cout << ob.minimumBoxes(apple, capacity) << endl;
	}
}

/*
2
3 5
1 3 2
4 3 1 5 2
3 4
5 5 5
2 4 2 7

2
4


*/