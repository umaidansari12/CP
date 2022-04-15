/*Lets consider the ways to get to stair i str[i]

Then str[i] = str[i - 1] + str[i - 2]

              Compute the array for all i from 2 to n*/

/*C++

class Solution {
public:
	long long countWays(int n) {
		int mod = 1000000007;


		if (n <= 1) return 1;

		//initializing base case
		long long a = 1, b = 1, temp;

		//same algorithm as Fibonacci
		//numbers adding current - 1 and
		//current - 2
		for (int i = 2; i <= n; i++)
		{

			temp = (a + b) % mod;
			a = b;
			b = temp;
		}

		//returning number of ways
		return b;
	}
};
*/

class Solution {
public:
	long long fib(int n)
	{
		if (n <= 1)
			return 1;
		long long a = 1, b = 1, temp, p = 1e9 + 7;
		for (int i = 2; i < n; i++)
		{
			temp = (a + b) % p;
			a = b;
			b = temp;
		}
		return b;
	}
	long long countWays(int N) {
		// your code here
		return fib(N + 1);
	}
};

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<vector<int>>&res, vector<int>&r, int sum, long long& count, long long p)
{
	if (sum == 0)
	{
		//res.push_back(r);
		count = ((count % p) + (1 % p)) % p;
		for (int i : r)
			cout << i << " ";
		cout << endl;
		return;
	}
	if (sum < 0)
	{
		return;
	}
	for (int i = 1; i <= 2; i++)
	{
		r.push_back(i);
		solve(res, r, sum - i, count, p);
		r.pop_back();
	}
	return;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> res;
		vector<int> r;
		long long count = 0, p = 1e+7;
		solve(res, r, n, count, p);
		cout << count << endl;
		cout << "-------" << endl;
	}


	return 0;
}