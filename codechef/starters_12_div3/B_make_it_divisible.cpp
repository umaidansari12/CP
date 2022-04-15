#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1)
			cout << "3\n";
		else {
			for (int i = 1; i <= n; i++)
			{
				if (i == 1 or i == n)
					cout << "3";
				else
					cout << "0";
			}
			cout << endl;
		}
		// if (n == 1)
		// 	cout << "3\n";
		// else if (n == 2)
		// 	cout << "15\n";
		// else {
		// 	n -= 3;
		// 	cout << "123";
		// 	while (n--)
		// 		cout << "0";
		// 	cout << "\n";
		// }
		// long long int low = pow(10, n - 1);
		// long long int high = pow(10, n) - 1;
		// for (long long int i = low; i <= high; i++) {
		// 	if ((i % 2) != 0 and (i % 3) == 0 and (i % 9) != 0)
		// 	{
		// 		cout << i << endl;
		// 		break;
		// 	}
		// }
	}

	return 0;
}