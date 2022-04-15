#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int partition(vector<int> &a, int l, int h)
{
	int i = l - 1, pivot = a[h];
	for (int j = l; j < h; j++)
	{
		if (a[j] < pivot)
		{
			swap(a[++i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return i + 1;
}

void quickSort(vector<int> &a, int l, int h)
{
	if (l >= h)
		return;
	int p = partition(a, l, h);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, h);
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
		cout << "Before : \n";
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cout << a[i] << " ";
		}
		cout << endl;
		quickSort(a, 0, n - 1);
		cout << "After : \n";
		for (auto i : a)
			cout << i << " ";
		cout << endl;

	}


	return 0;
}