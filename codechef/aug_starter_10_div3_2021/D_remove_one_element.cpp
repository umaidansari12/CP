#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n - 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < (n - 1); i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = n - 1, j = n - 2;
	long long int ans = LLONG_MIN;
	while (j >= 0)
	{
		ans = max(ans, abs(a[i] - b[j]));
		i--;
		j--;
	}
	return ans;
}

long long int solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n - 1);
	unordered_set<ll> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < (n - 1); i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long int ans = b[0] - a[1];
	//ans=max(b[0]-a[0],b[0]-a[1]);
// 	int i = n - 1, j = n - 2;
//
// 	while (j >= 0)
// 	{
// 		ans = max(ans, abs(a[i] - b[j]));
// 		i--;
// 		j--;
// 	}
	for (auto i : b)
	{
		if (s.count(i - ans) == 0)
		{
			ans = b[0] - a[0];
			break;
		}
	}
	if (ans <= 0) ans = b[0] - a[0];
	return ans;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	return 0;
}