#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAX 10000

class Solution {
public:
	long long int largestPrimeFactor(int N) {
		// code here
		bool prime[N + 1];
		memset(prime, true, sizeof(prime));
		prime[0] = prime[1] = false;
		for (int i = 2; i <= N; i++)
		{
			if (prime[i])
			{
				for (int j = i * i; j <= N; j += i)
				{
					prime[j] = false;
				}
			}
		}
		long long int ans = INT_MIN;
		for (long long int i = 2; i <= N; i++)
		{
			if (prime[i] && N % i == 0)
			{
				ans = max(ans, i);
				N /= i;
			}
		}

		return ans;

	}
};



int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/


	int T;
	cin >> T;
	while (T--)
	{
		//cout << 1 << endl;
		vector<bool> prime(10001, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i  <= 10000; i++)
		{
			if (prime[i])
			{
				for (int j = i * i; j <= 10000; j += i)
				{
					prime[j] = false;
				}
			}
		}

		int n;
		cin >> n;

		long long int ans = INT_MIN;
		for (long long int i = 2; i * i <= MAX; i++)
		{
			if (prime[i] && n % i == 0)
			{
				ans = max(ans, i);
			}

		}
		cout << ans << endl;
	}


	return 0;
}