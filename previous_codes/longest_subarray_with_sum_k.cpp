#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int lenOfLongSubarr(int A[],  int N, int K)
	{
		// Complete the function
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			int sum = 0;
			for (int j = i; j < N; j++)
			{
				sum += A[j];
				if (sum == K)
					ans = max(ans, j - i + 1);
			}
		}
		return ans;
	}

};

//wrong
class Solution {
public:
	int lenOfLongSubarr(int A[],  int N, int K)
	{
		// Complete the function
		int ans = 0, sum = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < N; i++)
		{
			sum += A[i];
			if (sum == K)
				ans = max(ans, i + 1);
			if (m.find(sum - K) != m.end())//if(m.find(abs(sum-K))!=m.end()) also wrong
				ans = max(ans, i - m[sum - K]);
			else
				m[sum - K] = i;

		}
		return ans;
	}

};

class Solution {
public:
	int lenOfLongSubarr(int A[],  int N, int K)
	{
		// Complete the function
		int ans = 0, sum = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < N; i++)
		{
			sum += A[i];
			if (sum == K)
				ans = max(ans, i + 1);
			if (m.find(sum) == m.end())
				m[sum] = i;
			if (m.find(sum - K) != m.end())
				ans = max(ans, i - m[sum - K]);

		}
		return ans;
	}

};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}