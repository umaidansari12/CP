#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tripletsInGP(vector<int> arr, int n, int r)
{
	unordered_map<long, long> left, right;
	for (int i = 0; i < n; i++)
	{
		left[arr[i]] = 0;
		right[arr[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		right[arr[i]]--;
		if (arr[i] % r == 0)
		{
			long a = arr[i] / r;
			long b = arr[i];
			long c = arr[i] * r;
			ans += (left[a] * right[c]);

		}
		left[arr[i]]++;
	}
	return ans;
}

long countTriplets(vector<long> arr, long r) {
	unordered_map<long, long> left, right;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		left[arr[i]] = 0;
		right[arr[i]]++;
	}
	long ans = 0;
	for (int i = 0; i < n; i++)
	{
		right[arr[i]]--;
		if (arr[i] % r == 0)
		{
			ans += (left[arr[i] / r] * right[arr[i] * r]);
		}
		left[arr[i]]++;
	}
	return ans;


}

long countTriplets1(vector<long> arr, long r) {
	long ans = 0;
	int n = arr.size();
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i]*r == arr[j])
			{
				for (int k = j + 1; k < n; k++)
				{
					if (arr[k] == arr[j]*r)
					{
						ans++;
					}
				}
			}
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
		int n, r;
		cin >> n >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << tripletsInGP(a, n, r) << endl;
	}


	return 0;
}