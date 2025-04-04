#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	void pushZerosToEnd(int arr[], int n) {
		// code here
		vector<int> a;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
				cnt++;
			else
				a.push_back(arr[i]);
		}
		while (cnt--)
			a.push_back(0);
		for (int i = 0; i < a.size(); i++)
			arr[i] = a[i];

	}
};

class Solution {
public:
	void pushZerosToEnd(int arr[], int n) {
		// code here
		vector<int> a;
		for (int i = 0; i < n; i++) {
			if (arr[i] != 0)
				a.push_back(arr[i]);
		}
		int _size = a.size();
		for (int i = 0; i < n; i++) {
			if (i < _size)
				arr[i] = a[i];
			else
				arr[i] = 0;
		}
	}
};

int first = -1, last = 0;
for (int last = 0; last < n; last++) {
	if (arr[last] == 0) {
		first = last;
		break;
	}
}
if (first == -1)
	return;
for (int last = first + 1; last < n; last++) {
	if (arr[last] != 0) {
		swap(arr[last], arr[first]);
		first++;
		// doing first++, will always move to zero
		// if the first non zero number lies next then after swapping, doing first++ we again land to same 0 that means we still need to move this 0 to its correct place but if the next number is 0 that means we have moved previous zero to correct place, its time to move 1
	}
}

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int> pos;
		int n = nums.size(), ind = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] != 0)
				nums[ind++] = nums[i];
		for (int i = ind; i < n; i++)
			nums[i] = 0;
		// for(int i=0;i<n-p;i++)
		//     nums[i+p]=0;


	}
};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int> pos;
		int n = nums.size(), ind = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] != 0)
				swap(nums[ind++], nums[i]);
		// for(int i=ind;i<n;i++)
		//     nums[i]=0;
		// for(int i=0;i<n-p;i++)
		//     nums[i+p]=0;


	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		ob.pushZerosToEnd(arr, n);
		for (i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends