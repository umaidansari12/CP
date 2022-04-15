#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pairs {
	int sum;
	int f;
	int s;
};

bool compare(pairs a, pairs b) {
	return a.sum < b.sum;
}

bool noCommon(pairs a, pairs b) {
	if (a.f == b.f || a.f == b.s || a.s == b.f || a.s == b.s)
		return false;
	return true;
}

vector<vector<int> > fourSum(vector<int> &arr, int k) {
	// Your code goes here
	int n = arr.size();
	unordered_map<int, pair<int, int>> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			m[arr[i] + arr[j]] = {i, j};
		}
	}
	set<vector<int>> se;
	vector<vector<int>> res;
	vector<int> r(4);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];
			if (m.find(k - sum) != m.end())
			{
				pair<int, int> p = m[k - sum];
				if (p.first != i && p.first != j && p.second != i && p.second != j)
				{
					r[0] = arr[i];
					r[1] = arr[j];
					r[2] = arr[p.first];
					r[3] = arr[p.second];
					sort(r.begin(), r.end());
					se.insert(r);

				}
			}
		}
	for (auto i : se)
		res.push_back(i);
	return res;
}

/*vector<vector<int> > fourSum(vector<int> &arr, int k) {
	int n = arr.size();
	vector<pairs> a;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			pairs t;
			t.sum = arr[i] + arr[j];
			t.f = i;
			t.s = j;
			a.push_back(t);
		}
	}
	sort(a.begin(), a.end(), compare);
	/*for (auto i : a)
		cout << i.sum << " " << i.f << " " << i.s << endl;
	int i = 0, j = a.size() - 1;
	set<vector<int>> se;
	vector<vector<int> > res;
	vector<int> r(4);
	while (i < n && j >= 0)
	{
		if (a[i].sum + a[j].sum == k && noCommon(a[i], a[j]))
		{
			r[0] = arr[a[i].f];
			r[1] = arr[a[i].s];
			r[2] = arr[a[j].f];
			r[3] = arr[a[j].s];
			//sort(r.begin(), r.end());
			se.insert(r);
			i++;
			j--;
		}
		else if (a[i].sum + a[j].sum < k)
		{
			i++;
		}
		else
			j--;
	}
	for (auto i : se)
		res.push_back(i);
	//return vector<vector<int>>();
	return res;
}*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector < vector <int>> r = fourSum(a, k);
		for (auto i : r)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
		cout << endl;

	}


	return 0;
}