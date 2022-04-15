#include <bits/stdc++.h>

using namespace std;
using ll = long long;


pair<int, int> pairsBrute(vector<int> a, int n, int s)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] + a[j] == s)
				return make_pair(a[i], a[j]);

	return make_pair(-1, -1);
}

pair<int, int> pairsBetterSearch(vector<int> a, int n, int s)
{
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (binary_search(a.begin() + i + 1, a.end(), s - a[i]));
		return make_pair(a[i], s - a[i]);
	}
	return make_pair(-1, -1);
}
pair<int, int> pairsBetter(vector<int> a, int n, int s)
{
	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	while (i <= j)
	{
		int sum = a[i] + a[j];
		if (sum == s)
			return make_pair(a[i], a[j]);
		else if (sum < s)
			i++;
		else
			j--;
	}
	return make_pair(-1, -1);
}

pair<int, int> pairsOptimal(vector<int> arr, int n, int s)
{
	//map<int, int> m;
	unordered_set<int> m;
	for (int i = 0; i < n; i++)
	{
		if (m.find(s - arr[i]) != m.end())
			return make_pair(s - arr[i], arr[i]);
		m.insert(arr[i]);
	}
	return make_pair(-1, -1);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> s;

	pair<int, int> p = pairsOptimal(a, n, s);
	cout << p.first << " " << p.second << endl;
	return 0;
}