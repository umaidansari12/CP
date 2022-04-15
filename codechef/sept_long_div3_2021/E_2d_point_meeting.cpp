#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a = 1, b = 2;
	int res1 = a ^ b;
	int res2 = res1 ^ b;
	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}