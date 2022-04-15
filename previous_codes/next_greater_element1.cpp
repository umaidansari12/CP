#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j])
				{
					int r = -1;
					for (int k = j + 1; k < nums2.size(); k++)
					{
						if (nums2[k] > nums1[i])
						{
							r = nums2[k];
							break;
						}
					}
					res.push_back(r);
				}
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		stack<int> s;
		map<int, int> m;
		for (int i = 0; i < nums2.size(); i++)
		{
			while (!s.empty() && s.top() <= nums2[i] )
			{
				int n = s.top();
				s.pop();
				m[n] = nums2[i];
			}

			s.push(nums2[i]);
		}
		for (int i = 0; i < nums1.size(); i++)
		{
			if (m[nums1[i]] == 0)
				res.push_back(-1);
			else
				res.push_back(m[nums1[i]]);
		}

		return res;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}