#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*

O(n^2) runtime, O(1) space – Brute force:

The brute force approach is simple. Loop through each element x and
find if there is another value that equals to target – x. As finding another
value requires looping through the rest of array, its runtime complexity is O(n^2).

To improve on it, notice that when we fix one of the integers ‘curValue’, we know the value
of the other integer we need to find ( target - curValue ).
Then it becomes a simple search problem. You can store all the integers of the array in a hashmap
 and do a lookup to check if the elements exists in the map.

Have you checked cases where the element you are looking up in the map is same as the curValue.

For example, consider the following cases :

A: [4 4] target : 8
and A : [3 4] target : 8

The answer in first case should be [1 2] and in second case, it should be empty.*/

class Solution {
public:
	vector<int> twoSum(const vector<int> &num, int target) {

		// map to store the mapping from number to its index.
		map<int, int> M;
		vector<int> ans;

		for (int i = 0; i < num.size(); i++) {
			int required = target - num[i];
			if (M.find(required) != M.end()) {
				// We have our solution. index1 = M[required], index2 = i + 1 ( 1 based ).
				ans.push_back(M[required]);
				ans.push_back(i + 1);
				return ans;
			}
			if (M.find(num[i]) == M.end()) {
				// We want to maintain the minimum index at M[num[i]]. i + 1 will
				// obviously be greater than whats already present.
				M[num[i]] = i + 1;
			}
		}
		return ans;
	}
};

vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size(), i = 0, j = 0;
	vector <int> r;
	//sort(nums.begin(),nums.end());
	/*for(i=0;i<n-1;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	        if(nums[i]+nums[j]==target)
	        {
	            r.push_back(i); r.push_back(j);
	            break;
	        }
	    }
	}*/
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		if (m.find(target - nums[i]) != m.end())
		{
			r.push_back(m[target - nums[i]]);
			r.push_back(i);
			return r;
		}
		m[nums[i]] = i;
	}
	return r;
}

int two_sum(vector<int> a, int n, int k)
{
	sort(a.begin(), a.end());
	int i = 0, j = n - 1, count = 0;
	while (i < j)
	{
		if (a[i] + a[j] == k)
		{
			count++;
			i++;
			j--;
		}
		else if (a[i] + a[j] > k)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return count;
}
vector<int> Solution::twoSum(const vector<int> &A, int B) {
	int n = A.size();
	if (n < 2)
		return vector<int>();
	map<int, int> m;
	vector<int> r;
	/*int i1=INT_MAX,i2=INT_MIN;
	for(int i=0;i<n;i++)
	{
	    for(int j=i+1;j<n;j++)
	    {
	        if(A[i]+A[j]==B)
	        {
	            i1=min(i1,i+1);
	            i2=max(i2,j+1);
	        }
	    }
	}*/
	for (int i = 0; i < n; i++)
	{
		if (m.find(B - A[i]) != m.end())
		{
			r.push_back(m[B - A[i]] + 1);
			r.push_back(i + 1);
			return r;
		}
		if (m.find(A[i]) == m.end())
			m[A[i]] = i;
	}
	/*if(i1!=INT_MIN && i2!=INT_MAX)
	{
	r.push_back(i1);
	r.push_back(i2);
	}*/
	return r;
}

int twoSum(vector<int>& a, int n, int k)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == k)
			{
				count++;
			}
		}
	}
	return count;
}

int two_Sum(vector<int> &a, int n, int k)
{
	int count = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		count += m[k - a[i]];
		if (k - a[i] == a[i])
			count--;
	}
	return count / 2;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//cout << two_Sum(a, n, k) << endl;
		vector<int> r = twoSum(a, k);
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}