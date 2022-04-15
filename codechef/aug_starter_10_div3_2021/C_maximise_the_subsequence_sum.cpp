#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve1()
{
	long long int n, k, mi = LLONG_MAX;
	cin >> n >> k;
	vector<ll> a(n);
	// bool f = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0 and k > 0)
		{
			a[i] *= (-1);
			//cout << i << "\n";
			k--;
			// f = true;
		}
		// if (a[i] != 0)
		// 	mi = min(mi, a[i]);
	}

	long long int ans = accumulate(a.begin(), a.end(), 0);
	// if (f)
	// {
	// 	//cout << mi << endl;
	// 	ans -= mi;
	// }
	return ans < 0 ? 0 : ans;
}

long long int solve() {
	long long int n, k, sum = 0;
	cin >> n >> k;
	vector<ll> a(n);
	bool f = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	// if (k == 0)
	// {
	// 	if (sum < 0)
	// 		return 0;
	// 	else
	// 		return sum;
	// }
	sum = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0 and k-- > 0)
			a[i] *= (-1);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
			sum += a[i];
	}

	return sum;
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