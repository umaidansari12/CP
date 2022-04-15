#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int rightShift(int n)
{
	for (int i = 0; i < 40; i++)
	{
		n >>= 1;
	}
	return n;
}

int getBit(int n, int i)
{
	return ((n & (1 << i)) != 0);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << getBit(6, 3) << endl;


	return 0;
}