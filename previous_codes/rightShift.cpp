#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, count = 40;
	cin >> n;
	for (int i = 0; i < count; i++)
	{
		n >>= 1;
	}
	cout << n << endl;



	return 0;
}