#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int inversionCountBrute(vector<int> a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				count++;
	return count;
}


int merge(vector<int>& a, int l, int m, int h)
{
	int i = l, j = m, k = 0, count = 0;
	int temp[h - l + 1];
	while (i <= m - 1 && j <= h)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			count += (m - i);
			temp[k++] = a[j++];
		}
	}
	while (i <= m - 1)
		temp[k++] = a[i++];
	while (j <= h)
		temp[k++] = a[j++];
	k = 0;
	for (int i = l; i <= h; i++)
		a[i] = temp[k++];
	return count;
}

int mergeSort(vector<int>& a, int l, int h)
{
	int count = 0;
	if (l < h)
	{
		int m = (l + h) / 2;
		count += mergeSort(a, l, m);
		count += mergeSort(a, m + 1, h);
		count += merge(a, l, m + 1, h);
	}
	return count;
}

int inversionCount(vector<int> a, int n)
{
	return mergeSort(a, 0, n - 1);
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
		cout << inversionCount(a, n) << endl;

	}


	return 0;
}