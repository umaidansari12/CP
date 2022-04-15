#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
	int peakElement(int arr[], int n)
	{
		// Your code here
		int ans = -1;
		if (arr[0] >= arr[1])
			ans = 0;
		for (int i = 1; i < (n - 1); i++)
		{
			if (arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1])
				ans = i;
		}
		if (arr[n - 1] >= arr[n - 2])
			ans = n - 1;
		return ans;
	}
	int peakElementBinarySearch(int arr[], int n)
	{
		// Your code here
		int low = 0, high = n - 1, mid;
		while (low <= high) {
			mid = (low + high) / 2;
			// Compare middle element with its
			// neighbours (if neighbours exist)
			if ((mid == 0 or arr[mid] >= arr[mid - 1]) and (mid == n - 1 or arr[mid] >= arr[mid + 1]))
				return mid;
			// If middle element is not peak and its
			// left neighbour is greater than it,
			// then left half must have a peak element
			else if (mid > 0 and arr[mid - 1] > arr[mid])
				high = mid - 1;
			// If middle element is not peak and its
			// right neighbour is greater than it,
			// then right half must have a peak element
			else
				low = mid + 1;
		}
		return -1;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], tmp[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			tmp[i] = a[i];
		}
		bool f = 0;
		Solution ob;

		int A = ob. peakElement(tmp, n);

		if (A<0 and A >= n)
			cout << 0 << endl;
		else
		{
			if (n == 1 and A == 0)
				f = 1;
			else if (A == 0 and a[0] >= a[1])
				f = 1;
			else if (A == n - 1 and a[n - 1] >= a[n - 2])
				f = 1;
			else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
				f = 1;
			else
				f = 0;
			cout << f << endl;
		}

	}

	return 0;
}  // } Driver Code Ends