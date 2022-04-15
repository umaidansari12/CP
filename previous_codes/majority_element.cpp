#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Solution::majorityElement(const vector<int> &a) {
	int n = a.size(), maj_index = 0, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (count == 0)
		{
			maj_index = a[i];
		}
		if (maj_index == a[i])
			count++;
		else
			count--;
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == maj_index)
			count++;
	}
	if (count > (n / 2))
		return maj_index;
}


int get_majority(vector <int> a)
{
	map<long, int> c;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	auto i = c.begin();
	while (i != c.end())
	{
		if (i->second > (n / 2))
			return i->first;
		i++;
	}
	return -1;
}
int majorityElement(vector<int>& nums) {
	int n = nums.size(), cnt = 0, ele = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt == 0)
			ele = nums[i];
		if (ele == nums[i])
			cnt++;
		else
			cnt--;
	}

	return ele;
}
int get_majority(vector <int> a)
{
	map<long, int> c;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
		if (c[a[i]] > (n / 2))
			return a[i];
	}
	return -1;
}
int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << get_majority(a) << endl;
	}
	return 0;
}