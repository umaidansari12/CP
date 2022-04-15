#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int hogwartsComputation(vector<int>s, vector<int>r, int n, int m)
{
	vector<int> res;
	map<int, int> idx;
	for (int i = 0; i < n; i++)
	{
		idx[r[i]] = i;
	}
	int sum = 0;
	sort(r.begin(), r.end());
	for (int i = m - 1; i < n; i++)
	{
		sum += s[idx[r[i]]];
		res.push_back(s[idx[r[i]]]*r[i]);
		res.push_back(sum * r[m - 1]);
		//sum += s[idx[r[i]]];
	}
	res.push_back(sum * r[m - 1]);
	return *max_element(res.begin(), res.end());

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
		int n, m;
		cin >> n;
		vector<int> s(n);
		vector<int> r(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> r[i];
		}
		cin >> m;
		cout << hogwartsComputation(s, r, n, m) << endl;
	}


	return 0;
}