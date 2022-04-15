#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void merge(vector<int> &a, int l, int m, int h)
{
	int i = l, j = m, k = 0;
	int temp[h - l + 1];
	while (i <= m - 1 && j <= h)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m - 1)
		temp[k++] = a[i++];
	while (j <= h)
		temp[k++] = a[j++];
	k = 0;
	for (int i = l; i <= h; i++)
		a[i] = temp[k++];
}


void mergeSort(vector<int> &a, int l, int h)
{
	if (l < h)
	{
		int m = (l + h) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, h);
		merge(a, l, m + 1, h);
	}
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
		cout << "Before :\n";
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cout << a[i] << " ";
		}
		cout << endl;
		mergeSort(a, 0, n - 1);
		cout << "After :\n";
		for (auto i : a)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}