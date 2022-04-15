#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> leaders(vector<int> a, int n) {
	// code here
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		bool f = false;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				f = true;
				break;
			}
		}
		if (!f)
			res.push_back(arr[i]);
	}
	return res;
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
		int n, s = 0, e = 0, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<int> res = leaders(a, n);
		for (auto i : res)
			cout << i << " ";
		cout << endl;
		return 0;
	}