#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int rainsBrute(vector<int> arr, int n)
{
	if (n <= 2)
		return 0;
	int water = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int left = arr[i], right = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[j]);
		water += (min(right, left) - arr[i]);
	}
	return water;
}

int rains(vector<int> arr, int n)
{
	if (n <= 2)
		return 0;
	int water = 0;
	vector<int> left(n), right(n);
	left[0] = arr[0];
	right[n - 1] = arr[n - 1];
	for (int i = 1; i < n; i++)
	{
		left[i] = max(left[i - 1], arr[i]);
		right[n - i - 1] = max(right[n - i], arr[n - i - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		water += (min(right[i], left[i]) - arr[i]);
	}
	return water;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << rains(a, n) << endl;

	}


	return 0;
}