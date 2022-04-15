#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int lowerBound(vector<int> a, int s, int e, int key)
{
	int ans = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (a[mid] == key)
		{
			ans = mid;
			e = mid - 1;
		}
		else if (a[mid] < key)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return ans;
}
int upperBound(vector<int> a, int s, int e, int key)
{
	int ans = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (a[mid] == key)
		{
			ans = mid;
			s = mid + 1;
		}
		else if (a[mid] < key)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return ans;
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
		int n, key;
		cin >> n >> key;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int freq = upperBound(a, 0, n - 1, key) - lowerBound(a, 0, n - 1, key) + 1;
		cout << freq << endl;
	}

	return 0;
}