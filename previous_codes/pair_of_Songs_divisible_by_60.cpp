
// C++ Program to count pairs whose sum divisible
// by '4'
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int count4Divisibiles(int arr[], int n)
	{
		// Complete the function
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((arr[i] + arr[j]) % 4 == 0)
					count++;
			}
		}
		return count;
	}
};

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int n = time.size(), ans = 0;
		int count[60] = {0};
		for (int i = 0; i < n; i++)
			count[time[i] % 60]++;
		for (int i = 1; i < 30; i++)
		{
			ans += (count[i] * count[60 - i]);
		}
		ans += (sumOfn(count[0] - 1) + sumOfn(count[30] - 1));
		return ans;
	}
	int sumOfn(int n)
	{
		return n * (n + 1) / 2;
	}
};
class Solution {
public:
	int sumOfn(int n)
	{
		return n * (n + 1) / 2;
	}
	int count4Divisibiles(int arr[], int n)
	{
		// Complete the function
		int ans = 0;
		int count[4] = {0};
		for (int i = 0; i < n; i++)
			count[arr[i] % 4]++;
		for (int i = 1; i < 2; i++)
			ans += (count[i] * count[4 - i]);
		ans += (sumOfn(count[0] - 1));
		ans += (sumOfn(count[2] - 1));
		return ans;
	}
};
// { Driver Code Starts.
// Driver code
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution ob;
		cout << ob.count4Divisibiles(arr, n) << endl;
	}

	return 0;
}  // } Driver Code Ends