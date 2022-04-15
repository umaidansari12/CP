//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
{
	int t;  // number of test cases
	cin >> t;
	while (t--)
	{
		int n;  // size of the array
		cin >> n;
		vector<long long int> arr(n), vec(n);

		for (int i = 0; i < n; i++) // input the array
		{
			cin >> arr[i];
		}

		vec = productExceptSelf(arr, n);  // function call

		for (int i = 0; i < n; i++) // print the output
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelfBrute(vector<long long int>& nums, int n) {
	//code here
	vector<long long int> a;
	for (int i = 0; i < n; i++)
	{
		long long int pro = 1;
		for (int j = 0; j < n; j++)
			if (i != j)
				pro *= nums[j];
		a.push_back(pro);
	}
	return a;
}

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
	//code here
	if (n == 1)
	{
		nums[0] = 1;
		return nums;
	}
	vector<long long int> pre(n), suff(n), a;
	pre[0] = nums[0];
	suff[n - 1] = nums[n - 1];
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] * nums[i];
	for (int i = n - 2; i >= 0; i--)
		suff[i] = suff[i + 1] * nums[i];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			a.push_back(suff[1]);
		else if (i == n - 1)
			a.push_back(pre[n - 2]);
		else
			a.push_back(pre[i - 1]*suff[i + 1]);
	}

	return a;
}
