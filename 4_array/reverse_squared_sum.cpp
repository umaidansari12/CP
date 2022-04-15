#include<iostream>

using namespace std;

int main()
{
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = 0, flag = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (flag == 0)
				ans += (arr[i] * arr[i]);
			else
				ans -= (arr[i] * arr[i]);
			flag = 1 - flag;
		}
		cout << ans << endl;
	}
	return 0;
}