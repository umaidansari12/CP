#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 2437, b = 875;

	int x = a, y = b;
	while (x != y) {
		if (x > y)
			x = x - y;
		else if (x < y)
			y = y - x;
	}
	cout << x << " " << y << endl;


	return 0;
}