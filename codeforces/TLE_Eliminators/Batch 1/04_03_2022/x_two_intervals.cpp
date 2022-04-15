#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int l1, l2, r1, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	if (l2 > r1 or l1 > r2)
		cout << -1 << endl;
	else
		cout << max(l1, l2) << " " << min(r1, r2) << endl;


	return 0;
}