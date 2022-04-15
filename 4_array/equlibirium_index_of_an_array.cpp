#include <iostream>
using namespace std;
#include <stdio.h>

int findEquilibrium(int [], int );

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << findEquilibrium (a, n) << endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
	//Your code here
	for (int i = 0; i < n; i++) {
		int left = i - 1;
		int right = i + 1;
		int left_sum = 0;
		int right_sum = 0;
		while (left >= 0)
			left_sum += A[left--];
		while (right < n)
			right_sum += A[right++];
		if (left_sum == right_sum)
			return i;
	}
	return -1;
}

int findEquilibrium(int A[], int n)
{
	//Your code here
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i];
	}
	int left_sum = 0, right_sum = sum;
	for (int i = 0; i < n; i++) {
		right_sum -= A[i];
		if (left_sum == right_sum)
			return i;
		left_sum += A[i];
	}
	return -1;
}

int findEquilibrium(int A[], int n)
{
	//Your code here
	int pre[n], suff[n];
	pre[0] = A[0];
	suff[n - 1] = A[n - 1];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + A[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = suff[i + 1] + A[i];
	}
	for (int i = 0; i < n; i++) {
		if (pre[i] == suff[i])
			return i;
	}
	return -1;
}