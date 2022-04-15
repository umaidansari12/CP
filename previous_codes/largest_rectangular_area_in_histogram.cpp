#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int largestRectangularAreaInHistogram(vector<int>&a, int n)
{
	int i = 0;
	stack<int> s;
	int area = 0, t, res = 0;
	while (i < n)
	{
		if (s.empty() || a[s.top()] <= a[i])
			s.push(i++);
		else
		{
			t = s.top();
			s.pop();
			area = a[t] * (s.empty() ? i : i - s.top() - 1);
			//cout << i << " " << t << area << endl;
			res = max(res, area);
		}
	}
	while (!s.empty());
	{
		t = s.top();
		s.pop();
		area = a[t] * (s.empty() ? i : i - s.top() - 1);
		//cout << i << " " << t << " " << area << endl;
		res = max(res, area);
	}
	return res;
}

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size(), res = 0, i = 0, a = 0, t = 0;
		stack<int>s;
		while (i < n)
		{
			if (s.empty() || heights[s.top()] <= heights[i])
				s.push(i++);
			else
			{
				t = s.top();
				s.pop();
				a = heights[t] * (s.empty() ? i : i - s.top() - 1);
				res = max(res, a);
			}
		}
		while (!s.empty())
		{
			int t = s.top();
			s.pop();
			a = heights[t] * (s.empty() ? i : i - s.top() - 1);
			res = max(res, a);
		}
		return res;
	}
};

class Solution
{
public:
	//Function to find largest rectangular area possible in a given histogram.
	long long getMaxArea(long long arr[], int n)
	{
		// Your code here
		int left[n], right[n];
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			if (s.empty())
			{
				left[i] = 0;
				s.push(i);
			}
			else
			{
				while (!s.empty() and arr[s.top()] >= arr[i])
					s.pop();
				left[i] = s.empty() ? 0 : s.top() + 1;
				s.push(i);
			}

		}
		while (!s.empty())
			s.pop();
		for (int i = n - 1; i >= 0; i--)
		{
			if (s.empty())
			{
				right[i] = n - 1;
				s.push(i);
			}
			else
			{
				while (!s.empty() and arr[s.top()] >= arr[i])
					s.pop();
				right[i] = s.empty() ? n - 1 : s.top() - 1;
				s.push(i);
			}
		}
		long long res = 0;
		for (int i = 0; i < n; i++)
		{
			res = max(res, (long long)arr[i] * (long long)(right[i] - left[i] + 1));
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
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		/*int res = 0;
		for (int i = 0; i < n ; i++)
		{
			int l = i, r = i;
			while (l >= 0 && a[i] <= a[l])
				l--;
			while (r < n && a[i] <= a[r])
				r++;
			if (l == -1)
				l = 0;
			if (r == n)
				r = n - 1;
			int left = a[l], right = a[r];
			if (left < a[i])
				l++;
			if (right < a[i])
				r--;
			cout << l << " " << r << " " << ((r - l) + 1) * a[i] << endl;
			res = max(res, ((r - l) + 1) * a[i]);
		}*/
		cout << largestRectangularAreaInHistogram(a, n) << endl;
		//cout << res << endl;
	}


	return 0;
}