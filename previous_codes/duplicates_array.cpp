#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void find_duplicates(vector<int> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i])] >= 0)
			a[abs(a[i])] = -a[abs(a[i])];
		else
			cout << a[i] << " ";
	}
}
vector<int> duplicates(int a[], int n) {
	// code here
	vector <int> r;
	for (int i = 0; i < n; i++)
	{
		a[a[i] % n] += n;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] / n > 1)
			r.push_back(i);
	}
	if (r.size() == 0)
		r.push_back(-1);
	return r;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		find_duplicates(a, n);

	}


	return 0;
}