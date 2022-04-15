#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		for (int i = 0; i < n - k; i++)
		{
			int m = 0;
			for (int j = i; j < i + k; j++)
			{
				m = max(m, arr[j]);
			}
			for (int j = i; j < i + k; j++)
			{
				arr[j] = m;
			}
		}
		int sum = 0;
		for (auto i : arr)
			cout << i << " ";
		cout << endl;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		return sum;
	}
};


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
		Solution ob;
		cout << ob.maxSumAfterPartitioning(a, k) << endl;


	}


	return 0;
}