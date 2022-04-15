#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAX 1000000007
#define size 1000000000


void fibonacci(vector<int> &a)
{
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < 100000; i++)
	{
		a[i] = ((a[i - 1] % MAX) + (a[i - 2] % MAX)) % MAX;
	}
	// cout << a[1] << " " << a[5] << " " << a[6] << endl;
	// cout << a[0] << endl;
	for (int i = 1; i < 100000; i++)
	{
		//cout << a[i] << " ";
		a[i] = ((a[i] % MAX) + (a[i - 1] % MAX)) % MAX;
	}
	//cout << endl;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12
// 0 1 1 2 3 5 8 13 21 34 55 89
// 0 1 1 2 4 9 17 30 51 85 140 229

int main()
{
	ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int t;
	cin >> t;
	vector<int>a(100000, 0);
	fibonacci(a);
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		if (l == 0)
			cout << a[r] << endl;
		else
			cout << (a[r] - a[l - 1]) << endl;

	}

	return 0;
}