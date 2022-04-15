#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {


public:
	int maxSumIS(int a[], int n)
	{
		// Your code goes here
		vector<int> res;
		for (int i = 0; i < n; i++)
			res.push_back(a[i]);
		int ma = a[0];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (a[i] > a[j] && (res[i] < res[j] + a[i]))
				{
					res[i] = res[j] + a[i];
					ma = max(ma, res[i]);
				}
			}
		}
		return ma;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n, 0), res(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			res[i] = a[i];
		}
		int ma = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (a[i] > a[j] && (res[i] < res[j] + a[i]))
				{
					res[i] = res[j] + a[i];
					ma = max(ma, res[i]);
				}
			}
		}
		cout << ma << endl;
		for (auto i : res)
		{
			cout << i << " ";
		}
		cout << endl;
	}


	return 0;
}