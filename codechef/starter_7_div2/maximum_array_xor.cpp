#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int xorsum(int *a, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += (a[i] ^ i);
	return sum;
}

int solve(int *a, int size, int k, int idx)
{
	if (k == 0)
		return 0;
	int ans = 0, ans1 = 0;
	for (int i = 0; i < size; i++)
	{
		swap(a[i], a[idx]);
		ans = max(ans, xorsum(a, size));
		ans1 = solve(a, size, k - 1, i);
		swap(a[i], a[idx]);
	}
	return max(ans, ans1);

}


ll solveAnswer(int *a, int size, int k)
{
	for (int i = 0; i < min(2 * k, size); i++)
	{
		a[i] ^= (size - 1);
	}
	return xorsum(a, size);
	return min(2 * k, size) * (size - 1);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin	>> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll size = pow(2, n);
		// int a[size];
		// for (int i = 0; i < size; i++)
		// 	a[i] = i;
		ll ans = min(2 * k, size) * (size - 1);
		cout << ans << endl;

	}


	return 0;
}