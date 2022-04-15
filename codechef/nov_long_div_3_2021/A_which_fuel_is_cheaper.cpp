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
		long long int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		long long int petrol = (x + (a * k));
		long long int diesel = (y + (b * k));
		if ( petrol == diesel) {
			cout << "SAME PRICE\n";
		}
		else if (petrol > diesel) {
			cout << "DIESEL\n";
		}
		else if (petrol < diesel) {
			cout << "PETROL\n";
		}

	}
	return 0;
}