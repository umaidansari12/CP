#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void mergeInsertionsort(int arr1[], int arr2[], int n, int m)
{
	// code here
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] > arr2[0])
		{
			swap(arr1[i], arr2[0]);
			int ele = arr2[0];
			int k;
			for (k = 1; k < m && arr2[k] < ele; k++)
			{
				arr2[k - 1] = arr2[k];
			}
			arr2[k - 1] = ele;
		}
	}
}
void mergeBrute(int arr1[], int arr2[], int n, int m)
{
	// code here
	vector<int> r;
	for (int i = 0; i < n; i++)
	{
		r.push_back(arr1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		r.push_back(arr2[i]);
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < n; i++)
	{
		arr1[i] = r[i];
	}
	for (int i = 0; i < m; i++)
	{
		arr2[i] = r[n + i];
	}
}

void mergeTwoSorted(vector<int> &a, vector<int> &b, int n, int m)
{
	for (int i = m - 1; i >= 0; i--)
	{
		int last = a[n - 1], j;
		for (j = n - 1; j >= 0 && a[j] > b[i]; j--)
		{
			a[j + 1] = a[j];
		}
		if (j != n - 2 || last > b[i])
		{
			a[j + 1] = b[i];
			b[i] = last;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

void mergeTwoSortedEfficient(vector<int> &a, vector<int> &b, int n, int m)
{
	int gap = n + m;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		int i = 0, j = 0;
		for (i = 0; i + gap < n; i++)
		{
			if (a[i] > a[i + gap])
			{
				swap(a[i], a[i + gap]);
			}
		}
		for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
		{
			if (a[i] > b[j])
				swap(a[i], b[j]);
		}
		if (j < m)
		{
			for (j = 0; j + gap < m; j++)
			{
				if (b[j] > b[j + gap])
					swap(b[j], b[j + gap]);

			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
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
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> b(m);
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		mergeTwoSortedEfficient(a, b, n, m);
	}


	return 0;
}