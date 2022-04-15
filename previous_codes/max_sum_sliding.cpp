#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int max_sum_subarray(vector<int>&a, int n, int k)
{
	int m_sum = 0, c_sum = 0, i = 0;
	for (i = 0; i < k; i++)
	{
		c_sum += a[i];
	}
	m_sum = c_sum;
	for (; i < n; i++)
	{
		c_sum = c_sum + a[i] - a[i - k];
		if (c_sum > m_sum)
		{
			m_sum = c_sum;
		}
	}
	return m_sum;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << max_sum_subarray(a, n, k) << endl;
	}


	return 0;
}