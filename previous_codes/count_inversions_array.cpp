#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void bruteforce(vector<int> &a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				count++;
		}
	}
	cout << count << endl;
}

void multi_set_method(vector<int> &a, int n)
{
	multiset<int> s;
	int count = 0;
	s.insert(a[0]);
	for (int i = 1; i < n ; i++)
	{
		s.insert(a[i]);
		int dist = distance(s.upper_bound(a[i]), s.end());
		count += dist;
	}

	cout << count << endl;

}

long long int merge(vector<int>&a, vector<int>&temp, int left, int mid, int right)
{
	long long int invcount = 0, i, j, k;
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			invcount += (mid - i);
		}

	}
	while (i <= mid - 1)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];
	for (int i = left; i <= right; i++)
	{
		a[i] = temp[i];
	}
	return invcount;

}

long long int mergeSortmethod(vector<int>&a, vector<int>&temp, int left, int right)
{
	long long int mid, invcount = 0;
	if (right > left)
	{
		mid = (left + right) / 2;
		invcount += mergeSortmethod(a, temp, left, mid);
		invcount += mergeSortmethod(a, temp, mid + 1, right);
		invcount += merge(a, temp, left, mid + 1, right);
	}
	return invcount;
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
		int n;
		cin >> n;
		vector<int> a(n), temp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << mergeSortmethod(a, temp, 0, n - 1) << endl;

	}


	return 0;
}