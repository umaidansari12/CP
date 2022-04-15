#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++
class Solution
{
public:
	vector<int> sieveOfEratosthenes(int N)
	{
		// Write Your Code here
		vector<int> prime(N + 1, 1);
		prime[0] = prime[1] = 0;
		for (int i = 2; i <= N; i++)
		{
			if (prime[i])
			{
				for (int j = i * i; j <= N; j += i)
				{
					prime[j] = 0;
				}
			}
		}
		vector<int> res;
		for (int i = 2; i <= N; i++)
			if (prime[i])
				res.push_back(i);
		return res;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		Solution ob;
		vector<int> primes  = ob.sieveOfEratosthenes(N);
		for (auto prime : primes) {
			cout << prime << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends