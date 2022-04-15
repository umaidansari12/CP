#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maxSubarraySum(int arr[], int n) {

	// Your code here
	int res = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			res = max(res, sum);
		}
	}
	return res;
}

ll kadanesAlgoBrute(vector<ll> &a, int n)
{
	ll maxi = a[0];
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ll sum = a[0];
			for (int k = i + 1; k <= j; k++)
			{
				sum += a[k];
			}
			maxi = max(sum, maxi);
		}
	}
	return maxi;
}

ll kadanesAlgoBetter(vector<ll> &a, int n)
{
	ll maxi = a[0];
	for (int i = 0; i < n ; i++)
	{
		ll sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			maxi = max(sum, maxi);
		}
	}
	return maxi;
}


ll kadanesAlgo(vector<ll> &a, int n)
{
	ll max_current = 0, max_global = INT_MIN;
	for (int i = 0; i < n ; i++)
	{
		max_current += a[i];
		if (max_global < max_current)
			max_global = max_current;
		if (max_current < 0)
			max_current = 0;
	}
	return max_global;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		ll n;
		cin >> n;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << kadanesAlgoBrute(a, n) << endl;
	}


	return 0;
}