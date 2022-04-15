
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	long long power(int a, int n, long long mod)
	{
		if (n == 0)
			return 1;
		if (n % 2 == 0)
		{
			long long y = power(a, n / 2, mod) % mod;
			return ((y % mod) * (y % mod)) % mod;
		}
		return ((a % mod) * (power(a, n - 1, mod) % mod)) % mod;

	}
	int Nth_term(int a, int r, int n) {
		// Code here
		signed long long int ans = a;
		ans = a * (power(r, n - 1, 1000000007));
		return ans % 1000000007;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends