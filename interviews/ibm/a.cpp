#include <bits/stdc++.h>

using namespace std;

vector<long> getSmallestPalindrome(vector<int>&distance, vector<int>&targetDistance) {
	// int left = 0, _size = s.size();

	// for (int i = 0; i <= _size; i++) {
	// 	if (s[i] != s[_size - i - 1] and s[i] != '?' and s[_size - i - 1] != '?')
	// 		return "-1";
	// 	else if (s[i] == s[_size - i - 1] && s[i] == '?') {
	// 		s[i] = s[_size - i - 1] = 'a';
	// 	}
	// 	else if (s[i] == '?' and s[_size - i - 1] != '?')
	// 		s[i] = s[_size - i - 1];
	// 	else if (s[i] != '?' and s[_size - i - 1] == '?')
	// 		s[_size - i - 1] = s[i];
	// }
	// return s;
	vector<long>ans;
	for (int i = 0; i < targetDistance.size(); i++) {
		vector<int>temp;
		for (int j = 0; j < distance.size(); j++) {

			int val = abs(targetDistance[i] - distance[j]);
			temp.push_back(val);
		}
		int sum = 0;
		for (int k = 0; k < temp.size(); k++) {
			sum += temp[k];
		}
		ans.push_back(sum);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n, 0), b(q, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < q; i++) {
			cin >> b[i];
		}
		vector<long> ans = getSmallestPalindrome(a, b);
		for (auto a : ans)
			cout << a << " ";
		cout << endl;
	}
}