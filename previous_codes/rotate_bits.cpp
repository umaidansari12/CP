#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INT_BITS 32

int leftRotate(int n, int d)
{
	return (n << d) | (n >> (INT_BITS - d));
}

int rightRotate(int n, int d)
{
	return (n >> d) | (n << (INT_BITS - d));
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		cout << leftRotate(n, d) << endl;
		cout << rightRotate(n, d) << endl;
	}


	return 0;
}