#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string n, m;
	cin >> n;
	cin.ignore();
	cin >> m;
	cin.ignore();
	int i, j;
	cin >> i >> j;
	int a = 0;
	reverse(n.begin(), n.end());
	for (int k = j; k >= i; k--)
	{
		n[k] = m[a++];
	}
	reverse(n.begin(), n.end());
	cout << n << endl;




	return 0;
}