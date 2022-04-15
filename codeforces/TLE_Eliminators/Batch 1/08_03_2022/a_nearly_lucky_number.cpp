#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n, count = 0;
	cin >> n;
	while (n) {
		if ((n % 10) == 4) {
			count++;
		}
		else if ((n % 10) == 7) {
			count++;
		}
		n /= 10;
	}
	if (count == 4 or count == 7)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}