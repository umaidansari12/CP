#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solveBrute(long long int k, long long int s) {
	long long int count = 0;
	for (long long int x = 0; x <= k; x++) {
		for (long long int y = 0; y <= k; y++) {
			for (long long int z = 0; z <= k; z++) {
				if ((x + y + z) == s)
					count++;
			}
		}
	}

	cout << count << endl;

	// O(k^3)
}

void solveOptimal(long long int k, long long int s) {

	long long int count = 0;
	for (long long int x = 0; x <= k; x++) {
		for (long long int y = 0; y <= k; y++) {
			long long int z = s - x - y;
			// z>=0 we need to check this case when sum of x and y is greater than s so z becomes negative
			// z<=k we need to check this case when sum of x and y is 0 and z becomes equal to s and it may be the chance that s is greater than k
			// we need to follow the constraint that x and y and z lies between 0 and k
			if (z >= 0 and z <= k) {
				count++;
			}
		}
	}

	cout << count << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int k, s, count = 0;
	cin >> k >> s;
	solveOptimal(k, s);



	return 0;
}