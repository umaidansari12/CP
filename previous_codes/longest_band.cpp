#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestBand(vector<int> &arr, int N)
{
	unordered_set<int> s;
	for (int i = 0; i < N; i++)
	{
		s.insert(arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (s.find(arr[i] - 1) == s.end())
		{
			int count = 0;
			int ele = arr[i];
			while (s.find(ele) != s.end())
			{
				count++;
				ele++;
			}
			ans = max(ans, count);
		}
	}
	return ans;
}

int longestBandBrute(vector<int> v, int n)
{
	sort(v.begin(), v.end());
	int count = 1, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == v[i + 1])
			continue;
		if (v[i] + 1 == v[i + 1])
			count++;
		else
		{
			ans = max(ans, count);
			count = 1;
		}
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << longestBand(a, n) << endl;
	}


	return 0;
}