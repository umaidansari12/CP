#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a[3] = {0}, b[3] = {0}, AcountZero = 0, AcountOne = 0, BcountZero = 0, BcountOne = 0;
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
			if (a[i] == 1)
				AcountOne++;
			else
				AcountZero++;
		}
		for (int i = 0; i < 3; i++) {
			cin >> b[i];
			if (b[i] == 1)
				BcountOne++;
			else
				BcountZero++;
		}
		if ((AcountZero == BcountZero) and (AcountOne == BcountOne))
			cout << "Pass\n";
		else
			cout << "Fail\n";
	}


	return 0;
}