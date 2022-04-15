#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n = 10, steps = 0;
	//cin >> n;
	while (n != 0) {
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
			n--;
		steps++;
	}
	cout << steps << endl;


	return 0;
}