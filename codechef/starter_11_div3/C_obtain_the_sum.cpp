#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve1() {
	int n;
	long long int s;
	cin >> n >> s;
	vector<long long int> pre(n + 1, 0), suff(n + 1, 0), arr(n + 1, 0);
	arr[0] = 0;
	pre[0] = 0;
	suff[n] = n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		pre[i] = pre[i - 1] + arr[i];
		//cout << pre[i] << " ";
	}
	//cout << endl;
	for (int i = n - 1; i >= 1; i--)
	{
		suff[i] = suff[i + 1] + arr[i];
		//cout << suff[i] << " ";
	}
	// for (int i = 1; i <= n; i++)
	// 	cout << suff[i] << " ";
	// cout << endl;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		long long int sum = ((i - 1) >= 0 ? pre[i - 1] : 0 ) + ((i + 1) <= n ? suff[i + 1] : 0);
		if (sum == s)
		{
			cout << i << "\n";
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << -1 << endl;

}

void solve() {

	long long int n, s;
	cin >> n >> s;
	long long int sum = (n * (n + 1)) / 2;
	long long int x = sum - s;
	if (x >= 1 and x <= n)
		cout << x << endl;
	else
		cout << -1 << endl;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		//cout << "Hello\n";
		solve();
	}

	return 0;
}