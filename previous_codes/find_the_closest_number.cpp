#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findClosest(int arr[], int n, int target);


int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n, target;
		cin >> n >> target;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << findClosest(arr, n, target) << endl;
	}
}
// } Driver Code Ends


int getClosest(int val1, int val2,
               int target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}
int findClosest(int arr[], int n, int target)
{
	// Complete the function
	if (target <= arr[0])
		return arr[0];
	if (target >= arr[n - 1])
		return arr[n - 1];

	// Doing binary search
	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		/* If target is less than array element,
		    then search in left */
		if (target < arr[mid]) {

			// If target is greater than previous
			// to mid, return closest of two
			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
				                  arr[mid], target);

			/* Repeat for left half */
			j = mid;
		}

		// If target is greater than mid
		else {
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
				                  arr[mid + 1], target);
			// update i
			i = mid + 1;
		}
	}

	// Only single element left after search
	return arr[mid];
}

