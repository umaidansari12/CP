#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


//User function template for C++
class Solution {
public:

	int countTriplet(int arr[], int n)
	{
		// Your code goes here
		map<int, int> m;
		for (int i = 0; i < n; i++)
			m[arr[i]]++;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (m.find(arr[i] + arr[j]) != m.end())
					count++;
			}
		}
		return count;
	}
};

void findTriplet(int arr[], int n)
{
	// sort the array
	sort(arr, arr + n);

	// for every element in arr
	// check if a pair exist(in array) whose
	// sum is equal to arr element
	for (int i = n - 1; i >= 0; i--) {
		int j = 0;
		int k = i - 1;

		// Iterate forward and backward to find
		// the other two elements
		while (j < k) {

			// If the two elements sum is
			// equal to the third element
			if (arr[i] == arr[j] + arr[k]) {

				// pair found
				cout << "numbers are " << arr[i] << " "
				     << arr[j] << " " << arr[k] << endl;
				return;
			}

			// If the element is greater than
			// sum of both the elements, then try
			// adding a smaller number to reach the
			// equality
			else if (arr[i] > arr[j] + arr[k])
				j += 1;

			// If the element is smaller, then
			// try with a smaller number
			// to reach equality, so decrease K
			else
				k -= 1;
		}
	}

	// No such triplet is found in array
	cout << "No such triplet exists";
}


// { Driver Code Starts.


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

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
		cout << ob.countTriplet(arr, n) << "\n";

	}

	return 0;
}  // } Driver Code Ends