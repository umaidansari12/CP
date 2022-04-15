#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> majorityElement(vector<int>& nums) {
	int n = nums.size();
	map<int, int> count;
	for (int i = 0; i < n; i++)
	{
		count[nums[i]]++;
	}
	vector<int> res;
	auto i = count.begin();
	while (i != count.end())
	{
		if (i->second > (n / 3))
		{
			res.push_back(i->first);
		}
		i++;
	}
	return res;
}

vector<int> majorityElement(vector<int>& nums) {
	int n = nums.size(), num1 = -1, num2 = -1, c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == num1)
			c1++;
		else if (nums[i] == num2)
			c2++;
		else if (c1 == 0)
		{
			num1 = nums[i];
			c1 = 1;
		}
		else if (c2 == 0)
		{
			num2 = nums[i];
			c2 = 1;
		}
		else
		{
			c1--;
			c2--;
		}
	}
	c1 = 0, c2 = 0;
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == num1)
			c1++;
		if (nums[i] == num2)
			c2++;
	}
	if (c1 > (n / 3))
		res.push_back(num1);
	if (c2 > (n / 3))
		res.push_back(num2);
	return res;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	return 0;
}