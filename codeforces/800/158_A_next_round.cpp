#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n, k, ans = 0;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	// int value = arr[k - 1];
	// sort(arr, arr + n);
	// int zero_position = 0;
	// while (arr[zero_position] == 0)
	// 	zero_position++;
	// if (zero_position == n)
	// 	return 0;
	// int value_position = lower_bound(arr, arr + n, value) - arr;
	// //cout << value_position << " " << zero_position << endl;
	// return n - (value_position + zero_position);
	/*
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0 and arr[i] >= arr[k - 1])
			ans++;
	}

	return ans;
	*/
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << solve() << endl;


	return 0;
}