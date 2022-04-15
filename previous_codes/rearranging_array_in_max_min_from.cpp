// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(long long *arr, int n)
{
	// Your code here
	vector<long long> res(n, 0);
	for (int i = 0; i < n; i++)
		res[i] = arr[i];
	//sort(res.begin(),res.end());
	int i = 0, j = n - 1, k = 0;
	while (i <= j)
	{
		arr[k++] = res[j--];
		arr[k++] = res[i++];
	}
}

void rearrange(long long *arr, int n)
{
	// Your code here
	int k = 0, j = n - 1, ma = arr[n - 1] + 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] += (arr[j] % ma) * ma;
			j--;
		}
		else
		{
			arr[i] += (arr[k] % ma) * ma;
			k++;
		}
	}
	for (int i = 0; i < n; i++)
		arr[i] /= ma;
}

// { Driver Code Starts.

// Driver program to test above function
int main()
{
	int t;

	//testcases
	cin >> t;

	while (t--) {

		//size of array
		int n;
		cin >> n;

		long long arr[n];

		//adding elements to the array
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		//calling rearrange() function
		rearrange(arr, n);

		//printing the elements
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";

		cout << endl;
	}
	return 0;
}
// } Driver Code Ends