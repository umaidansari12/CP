#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<int, int>> housingBrute(vector<int> a, int n, int k)
{
	vector<pair<int, int>> res;
	for (int i = 0; i < n; i++)
	{
		int sum = a[i];
		for (int j = i + 1; j < n; j++)
		{
			sum += a[j];
			if (sum == k)
			{
				res.push_back({i, j});
				break;
			}
		}
	}
	return res;
}

vector<pair<int, int>> housingBinarySearch(vector<int> a, int n, int k)
{
	vector<pair<int, int>> res;
	vector<int> prefix(n, 0);
	prefix[0] = a[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + a[i];
	for (int i = 0; i < n - 1; i++)
	{

		if (binary_search(prefix.begin() + i + 1, prefix.end(), prefix[i] + k))
		{
			int idx = lower_bound(prefix.begin() + i + 1, prefix.end(), prefix[i] + k) - prefix.begin();
			res.push_back({i + 1 , idx});
		}
	}
	return res;
}

vector<pair<int, int>> housing(vector<int> a, int n, int k)
{
	vector<pair<int, int>> res;
	int i = 0, j = 1, sum = a[0];
	while (j < n)
	{
		if (sum == k)
		{
			res.push_back({i, j - 1});
			sum -= a[i++];
		}
		if (sum > k)
		{
			sum -= a[i++];
		}
		else
		{
			sum += a[j++];
		}

	}
	return res;
}

vector<pair<int, int>> housingOptimal(vector<int> a, int n, int k )
{
	vector<pair<int, int>> res;
	int i = 0, j = 0, sum = 0;
	while (j < n)
	{

		sum += a[j++];
		while (sum > k && i < j)
		{
			sum -= a[i++];
		}
		if (sum == k)
			res.push_back({i, j - 1});
	}
	return res;
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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<pair<int, int>> r = housingOptimal(a, n, k);
		for (auto i : r)
			cout << i.first << " " << i.second << endl;
		cout << endl;
	}

	return 0;
}