#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int NumberofElementsInIntersection (int a[], int b[], int n, int m )
{
	// Your code goes here
	set<int> s1, s2;
	for (int i = 0; i < n; i++)
		s1.insert(a[i]);
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (s1.find(b[i]) != s1.end() && s2.find(b[i]) == s2.end())
			count++;
		s2.insert(b[i]);
	}
	return count;
}

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> r;
		unordered_map<int, int> dict;
		for (int i = 0; i < n; i++)
			dict[nums1[i]]++;
		for (int i = 0; i < nums2.size(); i++)
		{
			if (--dict[nums2[i]] >= 0)
				r.push_back(nums2[i]);
		}
		return r;

	}
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> r;
		unordered_map<int, int> m1, m2;
		for (int i = 0; i < n; i++)
			m1[nums1[i]]++;
		for (int i = 0; i < nums2.size(); i++)
			m2[nums2[i]]++;
		for (auto i : m1)
		{
			m1[i.first] = min(m1[i.first], m2[i.first]);
			while (m1[i.first]--)
				r.push_back(i.first);
		}
		return r;

	}
};


class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = (int)nums1.size(), n2 = (int)nums2.size();
		int i1 = 0, i2 = 0;
		vector<int> res;
		while (i1 < n1 && i2 < n2) {
			if (nums1[i1] == nums2[i2]) {
				res.push_back(nums1[i1]);
				i1++;
				i2++;
			}
			else if (nums1[i1] > nums2[i2]) {
				i2++;
			}
			else {
				i1++;
			}
		}
		return res;
	}
};
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> dict;
		vector<int> res;
		for (int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
		for (int i = 0; i < (int)nums2.size(); i++)
			if (dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
		return res;
	}
};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s, s1;
		vector<int> r;
		for (int i = 0; i < nums1.size(); i++)
			s.insert(nums1[i]);
		for (int i = 0; i < nums2.size(); i++)
		{
			if (s.find(nums2[i]) != s.end() && s1.find(nums2[i]) == s1.end())
				r.push_back(nums2[i]);
			s1.insert(nums2[i]);
		}
		return r;
	}
};

int doUnion(int a[], int n, int b[], int m)  {
	//code here
	unordered_map<int, int> s;
	for (int i = 0; i < n; i++)
		s[a[i]]++;
	for (int i = 0; i < m; i++)
		s[b[i]]++;
	return s.size();
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}