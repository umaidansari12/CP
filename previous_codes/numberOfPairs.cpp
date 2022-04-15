#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:

	// X[], Y[]: input arrau
	// M, N: size of arrays X[] and Y[] respectively
	//Function to count number of pairs such that x^y is greater than y^x.
	long long countPairs(int X[], int Y[], int M, int N)
	{
		//Your code here
		int count = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				long long int pow1 = pow(X[i], Y[j]);
				long long int pow2 = pow(Y[j], X[i]);
				if (pow1 > pow2)
					count++;
			}
		}
		return count;
	}
	int getIndex(int y[] , int n , int ele) {

		int low = 0;
		int high = n - 1;
		int ans = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (y[mid] > ele) {
				ans = mid;
				high  = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return ans;
	}
	long long countPairs(int X[], int Y[], int M, int N)
	{
		//Your code here
		long long int ans = 0;
		sort(X, X + M);
		sort(Y, Y + N);
		int zeros = 0, ones = 0, three = 0, four = 0, two = 0;
		for (int i = 0; i < N; i++)
		{
			if (Y[i] == 0)
				zeros++;
			if (Y[i] == 1)
				ones++;
			if (Y[i] == 2)
				two++;
			if (Y[i] == 3)
				three++;
			if (Y[i] == 4)
				four++;
		}
		for (int i = 0; i < M; i++)
		{
			if (X[i] == 0)
				continue;
			else if (X[i] == 1)
				ans += (zeros);
			else if (X[i] == 2)
			{
				int idx = upper_bound(Y, Y + N, X[i]) - Y;
				ans += (N - idx);
				ans += zeros;
				ans += ones;
				ans -= three;
				ans -= four;
			}
			else
			{
				int idx = upper_bound(Y, Y + N, X[i]) - Y;
				ans += (N - idx);
				ans += zeros + ones;
				if (X[i] == 3) {
					ans += two;
				}
			}

		}
		return ans;

	}
};


// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N;
		cin >> M >> N;
		int i, a[M], b[N];
		for (i = 0; i < M; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < N; i++)
		{
			cin >> b[i];
		}
		Solution ob;
		cout << ob.countPairs(a, b, M, N) << endl;
	}
}  // } Driver Code Ends