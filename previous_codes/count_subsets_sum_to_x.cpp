#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countSubset(vector<int> arr, int n, int i, int x)
{
	if (i == n)
	{
		if (x == 0)
			return 1;
		else
			return 0;
	}
	return countSubset(arr, n, i + 1, x - arr[i]) + countSubset(arr, n, i + 1, x);
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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << countSubset(a, n, 0, x) << endl;
	}


	return 0;
}