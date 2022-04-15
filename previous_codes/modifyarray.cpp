#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void ModifyArray(int *arr, int n)
{
	for (int k = 0; k < n; k++)
	{
		if (arr[k] >= 0)
		{
			arr[k] = arr[k] * (n - k);
		}
		else
		{
			arr[k] = arr[k] * (n + k);
		}
	}
}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ModifyArray(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}