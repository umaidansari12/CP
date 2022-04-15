#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//minimize the cost of ith cyclic shift

void leftShift(int *arr, int n)
{
	int temp = arr[0];
	for (int i = 1; i < n; i++)
		arr[i - 1] = arr[i];
	arr[n - 1] = temp;
}

void rightShift(int *arr, int n)
{
	int temp = arr[n - 1];
	for (int i = n - 1; i >= 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = temp;
}

vector <int> costOfKthRightShift(int *arr, int n)
{
	vector<int> cost;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			if (arr[j] != (j + 1))
				cnt++;
		}
		cost.push_back(cnt);
		rightShift(arr, n);
	}
	return cost;
}

vector <int> costOfKthLeftShift(int *arr, int n)
{
	vector<int> cost;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			if (arr[j] != (j + 1))
				cnt++;
		}
		cost.push_back(cnt);
		leftShift(arr, n);
	}
	return cost;
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
		int n, k;
		cin >> n >> k;
		k %= n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> cost = costOfKthRightShift(a, n);

		//vector<int> cost = costOfKthLeftShift(a, n);
		cout << "Cost : ";
		for (auto i : cost)
			cout << i << " ";
		cout << '\n';
	}


	return 0;
}