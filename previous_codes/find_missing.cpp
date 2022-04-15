#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
	public int missingNumber(int[] nums) {
		int xor1 = 0, xor2 = 0;
		for (int i = 0; i < nums.length; i++)
			xor1 ^= nums[i];
		for (int i = 0; i <= nums.length; i++)
			xor2 ^= i;
		return xor1 ^ xor2;

	}
}

int findMissing(vector <int>a, int n)
{
	int total = (n * (n + 1)) / 2;
	//cout << total << endl;
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		sum += a[i];
	}
	//cout << sum << endl;
	return total - sum;
}

int findMissingxor(vector<int> a, int n)
{
	int xr = 0;
	for (int i = 0; i < n - 1; i++)
		xr ^= a[i];
	for (int i = 1; i <= n; i++)
		xr ^= i;
	return xr;
}

int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <int> a(n - 1);
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a[i];
		}
		cout << findMissingxor(a, n) << endl;
	}
	return 0;
}