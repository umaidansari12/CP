#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a < b && c < b)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}


	return 0;
}