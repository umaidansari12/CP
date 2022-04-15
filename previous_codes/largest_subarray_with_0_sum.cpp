#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maxLen(int A[], int n)
{
	// Your code here
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += A[j];
			if (sum == 0)
				ans = max(ans, j - i + 1);
		}
	}
	return ans;
}

int maxLen(int A[], int n)
{
	// Your code here
	int ans = 0, sum = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		sum += A[i];
		if (sum == 0)
			ans = max(ans, i + 1);
		if (m.find(sum) != m.end())
			ans = max(ans, i - m[sum]);
		else
			m[sum] = i;
	}
	return ans;
}
int maxlen(vector<int> a, int n)
{
	// Your code here
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += A[j];
			if (sum == 0)
			{
				count = max(count, j - i + 1);
			}
		}
	}
	return count;
}

int maxLen(vector<int> A, int n)
{
	int sum = 0, maxlen = 0;
	unordered_map<int, int> presum;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (a[i] == 0 && maxlen == 0) //edge case when the given element is 0 and maxlen is 0 then update it to 1 i.e length of subarray is 1
			maxlen = 1;
		if (sum == 0)//edge case when the sum becomes 0
			maxlen = i + 1;
		if (presum.find(sum) != presum.end())
		{
			maxlen = max(maxlen, i - presum[sum]);
		}
		else
		{
			presum[sum] = i;
		}
	}
	return maxlen;
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
		int N;
		cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		cout << maxLen(a, N) << endl;
	}


	return 0;
}