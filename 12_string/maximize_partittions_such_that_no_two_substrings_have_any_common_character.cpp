#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maximizePartition(string s) {
	unordered_map<char, int> mp;
	int count = 0, k = 0, c = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (mp[s[i]] == 0)
			mp[s[i]] = i;
	}
	k = mp[s[0]];
	for (int i = 0; i < s.size(); i++) {
		if (i <= k) {
			c++;
			k = max(k, mp[s[i]]);
		}
		else {
			count++;
			c = 1;
			k = max(k, mp[s[i]]);
		}
	}
	if (c != 0)
		count++;
	return count;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << maximizePartition(s) << endl;
	}

	return 0;
}