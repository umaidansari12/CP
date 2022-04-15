#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//top down is coming as wrong

int longestIncreasingSubsequenceTopDown(int a[], int idx, int n, int parent, vector<int>&dp)
{
	if (dp[idx] != INT_MIN)
		return dp[idx];
	if (idx == n)
		return 0;
	if (a[idx] > parent)
		return dp[idx] = max(dp[idx], max(1 + longestIncreasingSubsequenceTopDown(a[idx], idx + 1, n, a[idx], dp), longestIncreasingSubsequenceTopDown(a, idx + 1, n, parent, dp)));
	else
		return dp[idx] = max(dp[idx], longestIncreasingSubsequenceTopDown(a, idx + 1, n, parent, dp));
}
int longestSubsequence(int n, int a[])
{
	// your code here
	vector<int> dp(n, INT_MIN);
	longestIncreasingSubsequenceTopDown(a, 0, n, INT_MIN, dp);
	return *max_element(dp.begin(), dp.end());
}

int longestIncreasingSubsequence(vector<int>&a, int idx, int n, int parent)
{
	if (idx == n)
		return 0;
	if (a[idx] > parent)
		return max(1 + longestIncreasingSubsequence(a, idx + 1, n, a[idx]), longestIncreasingSubsequence(a, idx + 1, n, parent));
	else
		return longestIncreasingSubsequence(a, idx + 1, n, parent);
}

int longestSubsequence(int n, int a[])
{
	// your code here
	// this is the NlogN approach in this what we are doing is we are creating a resultant array in which we
	// push the first element of the array then we traverse the array and check the element which is present at the back
	// of the resultant array is less than that of the array element then we simply push it into the resultant array because we are trying to maintain a sorted order and
	// take as many as possible elements into the resultant array and if any bigger element is come we cant include other smaller elements so we need to remove it
	// and include smaller elements so if the array element is less than that present at the back then we do binary search in the result array
	// to find the position of the current array element and store the current array element there.

	// time complexity: O(nlogn) - > traversing n size array and doing binary search every time logn time

	vector<int> res;
	res.push_back(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (res.back() < a[i])
			res.push_back(a[i]);
		else
		{
			int ind = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
			res[ind] = a[i];
		}
	}
	int s = res.size();
	return res.size();
}

int longestIncreasingSubsequenceBottomUp(vector<int>&a, int n)
{
	// your code here
	vector<int> dp(n, 1);
	int len = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				dp[i] = max(dp[i], 1 + dp[j]);
				len = max(len, dp[i]);
			}
		}

	}
	int ind = -1;
	vector<int> res;
	for (int i = n - 1; i >= 0; i--)
	{
		if (len == dp[i])
		{
			ind = i;
		}
	}
	res.push_back(a[ind]);
	for (int i = ind; i >= 0; i--)
	{
		if ((dp[i] + 1) == dp[ind] and a[i] < a[ind])
		{
			ind = i;
			res.push_back(a[ind]);
		}
	}

	reverse(res.begin(), res.end());
	for (auto i : res)
		cout << i << " ";
	cout << endl;


	return len;

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
		//cout << longestIncreasingSubsequence(a, 0, n, INT_MIN) << endl;
		cout << longestIncreasingSubsequenceBottomUp(a, n) << endl;
	}


	return 0;
}