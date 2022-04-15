#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. For simplicity, we consider width as always smaller than or equal to depth.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with optimal substructure property.*/


int maxHeight(int height[], int width[], int length[], int n)
{

	int dp[6 * n];
	vector<pair<pair<int, int>, int> > v;
	memset(dp, 0, sizeof dp);
	v.clear();
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		a = height[i];
		b = width[i];
		c = length[i];
		v.push_back(make_pair(make_pair(a, b), c));
		v.push_back(make_pair(make_pair(b, a), c));
		v.push_back(make_pair(make_pair(a, c), b));
		v.push_back(make_pair(make_pair(c, a), b));
		v.push_back(make_pair(make_pair(b, c), a));
		v.push_back(make_pair(make_pair(c, b), a));


		sort(v.begin(), v.end());
	}


	sort(v.begin(), v.end());


	for (int i = 0; i < v.size(); i++)
	{
		dp[i] = v[i].second;
		for (int j = 0; j < i; j++)
		{
			if (v[i].first.first > v[j].first.first and v[i].first.second > v[j].first.second)
			{
				dp[i] = max(dp[i], dp[j] + v[i].second);
			}
		}
	}

	int m = INT_MIN;
	for (int i = 0; i < v.size(); i++)
		m = max(dp[i], m);

	return m;

}




int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}