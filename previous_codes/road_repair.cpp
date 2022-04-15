#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> crew_id(n);
	for (int i = 0; i < n; i++)
	{
		cin >> crew_id[i];
	}
	int m;
	cin >> m;
	vector<int> job_id(m);
	for (int i = 0; i < m; i++)
	{
		cin >> job_id[i];
	}
	sort(job_id.begin(), job_id.end());
	sort(crew_id.begin(), crew_id.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (abs(crew_id[i] - job_id[i]));
	}
	cout << ans << endl;



	return 0;
}