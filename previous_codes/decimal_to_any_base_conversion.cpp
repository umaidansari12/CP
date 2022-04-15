#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
	string getNumber(int B, int N)
	{
		// Write Your Code here
		string s;
		while (N)
		{
			int d = (N % B);
			if (d < 10)
			{
				s += to_string(d);
			}
			else
			{
				s += ('A' + d - 10);
			}
			N /= B;
		}
		reverse(s.begin(), s.end());
		return s;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int B, N;
		cin >> B >> N;
		Solution ob;
		string ans  = ob.getNumber(B, N);
		cout << ans << endl;
	}
	return 0;
}  // } Driver Code Ends