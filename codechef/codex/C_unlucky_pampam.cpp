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
		char p1, p2;
		cin >> p1 >> p2;
		if (p1 == 'P' or p2 == 'P')
		{
			if (p1 == 'P')
				cout << p2 << endl;
			else
				cout << p1 << endl;
		}
		else if (p1 == 'S' or p2 == 'S')
			cout << "S\n";
		else if (p1 == p2)
			cout << "-1\n";
		else
			cout << "D\n";
	}


	return 0;
}