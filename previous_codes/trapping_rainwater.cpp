#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int trappingWater(int a[], int n) {

	// Your code here
	int l = 0, r = n - 1, left = 0, right = 0, res = 0;
	while (l <= r)
	{
		if (a[l] <= a[r])
		{
			if (a[l] >= left)
				left = a[l];
			else
				res += (left - a[l]);
			l++;
		}
		else
		{
			if (a[r] >= right)
				right = a[r];
			else
				res += (right - a[r]);
			r--;
		}
	}
	return res;

}
int trappingWater(int arr[], int n) {

	// Your code here
	vector<int> prefix(n), suffix(n);
	prefix[0] = arr[0];
	suffix[n - 1] = arr[n - 1];
	for (int i = 1; i < n; i++)
		prefix[i] = max(arr[i], prefix[i - 1]);
	for (int i = n - 2; i >= 0; i--)
		suffix[i] = max(arr[i], suffix[i + 1]);
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		count += (min(prefix[i], suffix[i]) - arr[i]);
	}
	return count;

}


int trappingRainwater(vector<int> a, int n)
{
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int left = a[i], right = a[i];
		/*while (j > 0 && a[i] <= a[j])
		{
			j--;
		}
		cout << "J : " << j;
		while ((k < n) && a[i] <= a[k])
		{
			k++;
		}
		cout << " K : " << k << endl;
		if (j == i || k == i)
			continue;*/
		for (int j = 0; j < i; j++)
			left = max(left, a[j]);
		for (int j = i + 1; j < n; j++)
			right = max(right, a[j]);
		int m = min(left, right);
		//cout << "M : " << m << endl;
		count += (m - a[i]);
	}
	return count;
}

int trapping_Rainwater(vector<int> a, int n)
{
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int left = a[i], right = a[i], j = i, k = i;
		while (j >= 0)
		{
			left = max(left, a[j--]);
		}
		cout << "LEFT : " << left;
		while (k < n)
		{
			right = max(right, a[k++]);
		}
		cout << " RIGHT : " << right << endl;
		/*for (int j = 0; j < i; j++)
			left = max(left, a[j]);
		for (int j = i + 1; j < n; j++)
			right = max(right, a[j]);*/
		int m = min(left, right);
		//cout << "M : " << m << endl;
		count += (m - a[i]);
	}
	return count;
}

class Solution {
public:
	int trapBrute(vector<int>& height) {
		int n = height.size(), count = 0;
		for (int i = 1; i < n - 1; i++)
		{
			int left = height[i], right = height[i];
			for (int j = 0; j < i; j++)
				left = max(left, height[j]);
			for (int j = i + 1; j < n; j++)
				right = max(right, height[j]);
			int m = min(left, right);
			count += (m - height[i]);
		}
		return count;
	}
	int trapBetter(vector<int>& height) {
		int n = height.size();
		if (n == 0)
			return 0;
		vector<int> prefix_max(n), suffix_max(n);
		prefix_max[0] = height[0];
		suffix_max[n - 1] = height[n - 1];
		for (int i = 1; i < n; i++)
			prefix_max[i] = max(height[i], prefix_max[i - 1]);
		for (int i = n - 2; i >= 0; i--)
			suffix_max[i] = max(height[i], suffix_max[i + 1]);
		int count = 0;
		for (int i = 1; i < n; i++)
		{
			count = count + min(suffix_max[i], prefix_max[i]) - height[i];
		}
		return count;
	}
	int trapOptimal(vector<int>& height) {
		int n = height.size(), l = 0, r = n - 1, leftMax = 0, rightMax = 0, res = 0;
		while (l <= r)
		{
			if (height[l] <= height[r])
			{
				if (height[l] >= leftMax)
					leftMax = height[l];
				else
					res += (leftMax - height[l]);
				l++;
			}
			else
			{
				if (height[r] >= rightMax)
					rightMax = height[r];
				else
					res += (rightMax - height[r]);
				r--;
			}
		}
		return res;

	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << trappingRainwater(a, n) << endl;
	}


	return 0;
}