#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:

	bool outOfOrder(vector<int> arr, int i) {
		int x = arr[i];
		if (i == 0) {
			return x > arr[1];
		}
		if (i == arr.size() - 1) {
			return x < arr[i - 1];
		}
		return x > arr[i + 1] or x < arr[i - 1];

	}

	pair<int, int> subarraySort(vector<int> arr) {

		int smallest = INT_MAX;
		int largest = INT_MIN;

		for (int i = 0; i < arr.size(); i++) {
			int x = arr[i];

			if (outOfOrder(arr, i)) {
				smallest = min(smallest, x);
				largest = max(largest, x);
			}
		}

		//next step find the right index where smallest and largest lie (subarray) for out solution
		if (smallest == INT_MAX) {
			return { -1, -1};
		}

		int left = 0;
		while (smallest >= arr[left]) {
			left++;
		}
		int right = arr.size() - 1;
		while (largest <= arr[right]) {
			right--;
		}

		return {left, right};

	}
	vector<int> printUnsorted(int arr[], int n) {
		// code here
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			a[i] = arr[i];
		}
		sort(a.begin(), a.end());
		int start = INT_MAX, end = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != arr[i])
			{
				start = min(start, i);
				end = max(end, i);
			}
		}
		if (start == INT_MAX and end == INT_MIN)
		{
			return {0, 0};
		}
		else
			return {start, end};
	}
	vector<int> printUnsorted(int arr[], int n) {
		// code here
		int smallest = INT_MAX, largest = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (arr[i] > arr[i + 1])
				{
					smallest = min(smallest, arr[i]);
					largest = max(largest, arr[i]);
				}
			}
			else if (i == n - 1)
			{
				if (arr[i] < arr[i - 1])
				{
					smallest = min(smallest, arr[i]);
					largest = max(largest, arr[i]);
				}
			}
			else
			{
				if (arr[i] > arr[i + 1] or arr[i] < arr[i - 1])
				{
					smallest = min(smallest, arr[i]);
					largest = max(largest, arr[i]);
				}
			}
		}
		if (smallest == INT_MAX)
			return {0, 0};
		int left = 0;
		while (smallest >= arr[left])
			left++;
		int right = n - 1;
		while (largest <= arr[right])
			right--;
		return {left, right};
	}
	vector<int> printUnsorted(int arr[], int n) {
		// code here
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			a[i] = arr[i];
		}
		sort(a.begin(), a.end());
		int start = 0, end = n - 1;
		while (start < n and a[start] == arr[start])
			start++;
		while (end >= 0 and a[end] == arr[end])
			end--;
		if (start == n)
			return {0, 0};

		return {start, end};
	}

};

class Solution {
public:
	int findUnsortedSubarray(vector<int>& arr) {
		int n = arr.size();
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			a[i] = arr[i];
		}
		int cnt = 0, start = INT_MAX, end = INT_MIN;
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
		{
			if (a[i] != arr[i])
			{
				start = min(start, i);
				end = max(end, i);
			}
		}
		if (start == INT_MAX and end == INT_MIN)
			return 0;
		return end - start + 1;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.printUnsorted(arr, n);
		cout << ans[0] << " " << ans[1] << "\n";
	}
	return 0;
}
// } Driver Code Ends