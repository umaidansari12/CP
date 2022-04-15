#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int isSumEven(long long int a[], int k, int n)
{
	int sum = 0;
	for (int i = 0; i < k - 1; i++)
	{
		sum += a[i];
	}
	for (int i = k - 1; i < n; i++)
	{
		sum += a[i];
		if (sum % 2 == 0)
			return true;
		sum -= a[i - k + 1];
	}
	return false;
}

int solve2()
{
	int n;
	cin >> n;
	long long int a[n] = {0};
	for (int i = 1; i <= n; i++) a[i - 1] = i;
	int low = 3, high = n, mid, ans = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (isSumEven(a, mid, n))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return high;
}

int solve()
{
	int n;
	cin >> n;
	long long int a[n], pre[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		if (i == 0)
			pre[i] = a[i];
		else
			pre[i] = pre[i - 1] + a[i];
	}
	if (pre[n - 1] % 2 == 0)
		return n;
	else
		return n - 1;
}

void solve1() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 1; i <= n; i++) a[i - 1] = i;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum % 2 == 0)
			{
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans << '\n';
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