#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> tripletsBrute(vector<int> a, int n, int s)
{
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (a[i] + a[j] + a[k] == s)
				{
					res.push_back({a[i], a[j], a[k]});
				}
			}
		}
	}
	return res;
}

vector<vector<int>> tripletsOptimal(vector<int>a, int n, int s)
{
	sort(a.begin(), a.end());
	vector<vector<int>> res;
	for (int i = 0; i <= n - 3; i++)
	{
		int k = i + 1, j = n - 1;
		while (k < j)
		{
			int sum = a[i] + a[k] + a[j];
			if (sum == s)
			{
				res.push_back({a[i], a[k], a[j]});
				k++; j--;
			}
			else if (sum < s)
				k++;
			else
				j--;
		}
	}
	return res;
}


vector<vector<int>> tripletsBetterSearch(vector<int>a, int n, int s)
{
	sort(a.begin(), a.end());
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (binary_search(a.begin() + j + 1, a.end(), s - (a[i] + a[j])))
				res.push_back({a[i], a[j], s - (a[i] + a[j])});
		}
	}
	return res;
}

vector<vector<int>> tripletsBetter(vector<int>a, int n, int s)
{
	unordered_set<int> m;
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (m.find(s - (a[i] + a[j])) != m.end())
				res.push_back({a[i], a[j], s - (a[i] + a[j])});
		}
		m.insert(a[i]);
	}
	return res;
}

bool find3Numbers(int a[], int n, int s)
{
	//Your Code Here
	unordered_set<int> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (m.find(s - (a[i] + a[j])) != m.end())
				return true;
		}
		m.insert(a[i]);
	}

	return false;
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
	vector<vector<int>> r = tripletsBrute(a, n, s);
	for (auto i : r)
	{
		for (auto j : i)
			cout << j << ",";
		cout << endl;
	}

	return 0;
}