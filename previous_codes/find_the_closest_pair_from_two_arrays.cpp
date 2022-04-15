#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
{
	// Complete the function
	int ans = INT_MAX, left = 0, right = 0;
	int l = 0, r = m - 1;
	while (l < n && r >= 0)
	{
		int sum = arr[l] + brr[r];
		if (abs(x - sum) < abs(x - ans))
		{
			left = arr[l];
			right = brr[r];
			ans = sum;
		}
		/*	else if(abs(x - sum) == abs(x - ans))
			{
			    left = max(left,arr[l]);
				right = min(right,brr[r]);
				ans = sum;
			}*/
		if (sum == x)
		{
			vector<int> res;
			res.push_back(left);
			res.push_back(right);
			return res;
		}
		else if (sum < x)
			l++;
		else
			r--;
	}
	vector<int> res;
	res.push_back(left);
	res.push_back(right);
	return res;
}


vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
{
	// Complete the function
	int ans = INT_MAX, left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = arr[i] + brr[j];
			if (abs(x - sum) < abs(x - ans))
			{
				left = arr[i];
				right = brr[j];
				ans = sum;
			}
			else if (abs(x - sum) == abs(x - ans))
			{
				left = min(arr[i], left);
				right = max(brr[j], right);
				ans = sum;
			}
		}
	}
	vector<int> res;
	res.push_back(left);
	res.push_back(right);
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}