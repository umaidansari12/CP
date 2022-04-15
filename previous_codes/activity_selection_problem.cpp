#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include<vector>
#include<algorithm>
using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b)
{
	return a.second < b.second;
}

int countActivites(vector<pair<int, int> > activities) {
	//Complete this method
	sort(activities.begin(), activities.end(), comp);
	int n = activities.size();
	int count = 1;
	for (auto i : activities)
		cout << i.first << " " << i.second << endl;
	pair<int, int> e = activities[0];
	for (int i = 1; i < n; i++)
	{
		if (activities[i].first >= e.second)
		{
			count++;
			e = activities[i];
		}
	}
	return count;



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
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i].first >> a[i].second;
		cout << countActivites(a) << endl;
	}


	return 0;
}