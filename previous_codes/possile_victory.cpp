#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, o, c;
	cin >> r >> o >> c;
	o = 20 - o;
	if (c + (36 * o) > r)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}