#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int closestToZero(int arr[], int n)
	{
		// your code here
		sort(arr, arr + n);
		int min_sum = INT_MAX;
		int l = 0, r = n - 1;
		while (l < r)
		{
			int sum = arr[l] + arr[r];
			if (sum == 0)
				return 0;
			if (abs(min_sum) > abs(sum))
			{
				min_sum = sum;
			}
			if (abs(sum) == abs(min_sum))
			{
				if (sum > min_sum)
					min_sum = sum;
			}
			if (sum < 0)
				l++;
			else
				r--;
		}

		return min_sum;
	}
	int closestToZero(int arr[], int n)
	{
		// your code here
		sort(arr, arr + n);
		int l = 0, r = n - 1, ans = INT_MAX, res = -1, min = 0;
		while (l < r)
		{
			int sum = arr[l] + arr[r];
			if (abs(sum) <= abs(ans))
			{
				ans = sum;
				if (ans > 0)
					min = ans;
				//res=sum;
			}
			if (sum == 0)
			{
				return sum;
			}
			else if (sum > 0)
			{
				//	ans=max(ans,sum);
				r--;
			}
			else
			{
				//	ans=min(ans,sum);
				l++;
			}
		}
		if (abs(ans) == min)
			return min;
		else
			return ans;
	}
};


class Solution
{
public:
	int closestToZero(int arr[], int n)
	{
		// your code here
		sort(arr, arr + n);
		int l = 0, r = n - 1, minDiff = INT_MAX; //ans=INT_MIN;
		vector<int> ans;
		while (l < r)
		{
			int sum = arr[l] + arr[r];
			ans.push_back(sum);
			if (sum == 0)
			{
				return sum;
			}
			else if (sum < 0)
			{
				//ans=max(ans,sum);
				l++;
			}
			else
			{
				//ans=min(ans,sum);
				r--;
			}
		}
		r = INT_MIN;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] < 0)
				r = max(r, ans[i]);
			else if (ans[i] > 0)
				r = ans[i];
		}
		return r;
	}
};
// } Driver Code Ends


class Solution
{
public:
	int closestToZero(int arr[], int n)
	{
		// your code here
		/*int ans = , l = 0, r = n - 1, minDiff = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((arr[j] + arr[i]) < minDiff)
				{
					minDiff = arr[j] + arr[i];
					ans = max(ans, arr[j] + arr[i]);
				}

			}
		}
		return ans;*/
		int closestToZero(int arr[], int n)
		{
			// your code here
			int ans = INT_MAX, l = 0, r = n - 1, minSum = arr[0] + arr[1];
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					int sum = arr[j] + arr[i];
					if (abs(minSum) > abs(sum))
						minSum = sum;
				}
			}
			return minSum;
		}
	}
};

// { Driver Code Starts.
int main ()
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
		cout << ob.closestToZero(arr, n) << endl;
	}
}  // } Driver Code Ends