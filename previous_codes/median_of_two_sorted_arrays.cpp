#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> n;
		for (int i = 0; i < nums1.size(); i++)
			n.push_back(nums1[i]);
		for (int j = 0; j < nums2.size(); j++)
			n.push_back(nums2[j]);
		sort(n.begin(), n.end());
		int size = n.size();
		double ans = 0.0;
		if (size % 2 == 0)
		{
			size = size / 2;
			ans = ((double)n[size] + (double)n[size - 1]) / 2.0;
		}
		else
			ans = (double)n[size / 2];
		return ans;

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
		vector<int> a(n), b(n), res(2 * n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			res[i] = a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			res[n + i] = b[i];
		}
		sort(res.begin(), res.end());
		cout << (res[n] + res[n - 1]) / 2 << endl;
	}


	return 0;
}