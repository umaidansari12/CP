#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, cnt = 0;
		cin >> n >> k;
		//int a[n] = {0};
		//for (int i = 0; i < n; i++)
		//a[i] = i + 1;
		//reverse case fails when the number of (n-k) elements will be odd as one element will still be at its position
		// reverse(a + k, a + n);
		// for (int i = 0; i < n; i++)
		// {
		// 	if (a[i] == (i + 1))
		// 		cnt++;
		// }
		// if (cnt == k)
		// {
		// 	for (int i = 0; i < n; i++)
		// 		cout << a[i] << " ";
		// 	cout << endl;
		// }
		// else
		// 	cout << -1 << endl;
		if (k == n)
		{
			//place n elements at its proper position
			for (int i = 1; i <= n; i++)
				cout << i << " ";
			cout << endl;
		}
		else if (k == (n - 1))
		{
			//if n-1 elements are at its position then one last element will automatically be at its position
			cout << -1 << endl;
		}
		else
		{
			//place first k elements at its position then do the cyclic shift of (n-k) elements so that they are distoreted
			for (int i = 1; i <= k; i++)
				cout << i << " ";
			for (int i = k + 2; i <= n; i++)
				cout << i << " ";
			cout << k + 1 << endl;
		}
	}
	return 0;
}