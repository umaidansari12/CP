#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool comp(const vector<int> a, const vector<int> b)
{
	return a[1] > b[1];
}
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	sort(boxTypes.begin(), boxTypes.end(), comp);
	int ans = 0;
	/*for (auto i : boxTypes)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}*/

	for (int i = 0; i < boxTypes.size(); i++)
	{
		if (truckSize >= boxTypes[i][0])
		{
			truckSize -= boxTypes[i][0];
			ans += (boxTypes[i][0] * boxTypes[i][1]);
		}
		else
		{
			ans += (truckSize * boxTypes[i][1]);
			truckSize = 0;
		}
	}
	return ans;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, size;
		cin >> n >> size;
		vector<vector<int>> v(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++)
			cin >> v[i][0] >> v[i][1];
		cout << maximumUnits(v, size) << endl;
	}


	return 0;
}