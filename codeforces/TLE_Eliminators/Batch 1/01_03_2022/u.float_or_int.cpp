#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	float n;
	cin >> n;

	// int num = n;
	// float n1 = num;

	// if (n1 == n) {
	// 	cout << "int " << (int)n;
	// }
	// else {
	// 	cout << "float " << num << " " << float(n - num);
	// }
	int num = n;

	if (n - num > 0) {
		cout << "float " << num << " " << float(n - num);
	}
	else {
		cout << "int " << (int)n;
	}


	return 0;
}