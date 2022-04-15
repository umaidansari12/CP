#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int b[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			return false;
	}
	return true;
}


int main()
{
	int t;
	cin >> t;
	while (t--) {

		if (solve() == true)
			cout << "True\n";
		else
			cout << "False\n";
	}
}