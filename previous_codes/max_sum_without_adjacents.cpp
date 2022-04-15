#include <bits/stdc++.h>
/*
Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including the previous element and
excl = Max sum excluding the previous element.

Max sum excluding the current element will be max(incl, excl)
 and max sum including the current element will be excl + current element .*/

using namespace std;
using ll = long long;

class Solution
{

public:
	int maxSum(int arr[], int n)
	{
		int incl_curr = arr[0];
		int excl_curr = 0;
		int incl_prev = incl_curr;
		int excl_prev = excl_curr;

		for (int i = 1; i < n; i++)
		{
			excl_curr = max(incl_prev, excl_prev);
			incl_curr = excl_prev + arr[i];
			excl_prev = excl_curr;
			incl_prev = incl_curr;
		}
		return max(excl_curr, incl_curr);
	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}