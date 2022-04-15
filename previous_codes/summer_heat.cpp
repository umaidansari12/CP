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
	while (t--)
	{
		int xa, xb, Xa, Xb;
		cin >> xa >> xb >> Xa >> Xb;
		cout << (Xa / xa) + (Xb / xb) << endl;
	}



	return 0;
}