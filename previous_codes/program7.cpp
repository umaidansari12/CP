#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int a, b;
	cin >> a >> b;
	reverse(arr + a, arr + b + 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}