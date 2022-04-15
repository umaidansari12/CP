//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
public:
	//Function to find the nth catalan number.

	cpp_int TopDownHelper(int n, vector<cpp_int> &dp)
	{
		if (n == 0 or n == 1)
			return 1;
		if (dp[n] != 0)
			return dp[n];

		cpp_int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cpp_int x = TopDownHelper(i - 1, dp);
			cpp_int y = TopDownHelper(n - i, dp);
			ans += (x * y);
		}
		return dp[n] = ans;
	}

	cpp_int findCatalanTopDown(int n)
	{
		//code here
		vector<cpp_int> dp(n + 1, cpp_int(0));
		return solve(n, dp);

	}

	cpp_int findCatalan(int n)
	{
		//code here
		if (n == 0 or n == 1)
			return 1;
		cpp_int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cpp_int x = findCatalan(i - 1);
			cpp_int y = findCatalan(n - i);
			ans += (x * y);
		}
		return ans;

	}

	cpp_int findCatalanBottomUp(int n)
	{
		//code here
		vector<cpp_int> dp(n + 1, cpp_int(0));
		dp[0] = dp[1] = 1;
		for (int i = 1; i <= n; i++)
		{
			cpp_int ans = 0;
			for (int j = 1; j <= i; j++)
			{
				cpp_int x = dp[j - 1];
				cpp_int y = dp[i - j];
				ans += (x * y);
			}
			dp[i] = ans;
		}
		return dp[n];

	}
};

// { Driver Code Starts.

int main()
{
	//taking count of testcases
	int t;
	cin >> t;
	while (t--) {

		//taking nth number
		int n;
		cin >> n;
		Solution obj;
		//calling function findCatalan function
		cout << obj.findCatalan(n) << "\n";
	}
	return 0;
}  // } Driver Code Ends