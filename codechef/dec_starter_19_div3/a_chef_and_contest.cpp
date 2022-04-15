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
		long long int x, y, p, q, chef = 0, chefina = 0;
		cin >> x >> y >> p >> q;
		chef = x + (p * 10);
		chefina = y + (q * 10);
		if (chef == chefina)
			cout << "Draw\n";
		else if (chef < chefina)
			cout << "Chef\n";
		else
			cout << "Chefina\n";
	}


	return 0;
}