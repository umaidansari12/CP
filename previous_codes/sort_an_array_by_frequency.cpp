#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> frequencySort(vector<int>& nums) {
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]]++;
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < nums.size(); i++)
		v.push_back({nums[i], m[nums[i]]});

	sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	});
	for (int i = 0; i < v.size(); i++)
		nums[i] = v[i].first;
	return nums;

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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		frequencySort(a);
		for (auto i : a)
			cout << i << " ";
		cout << endl;

	}


	return 0;
}