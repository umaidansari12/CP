#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int SOD(long long int x) {
	long long int sum = 0;
	while (x) {
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

// A well known theorem from elementary number theory goes as follows:

// A number is divisible by 33 if and only if the sum of its digits is divisible by 33.

// Thus, the number of integers in the range [L, R][L,R] whose sum of digits is divisible by 33 is equal to the number of integers in the range divisible by 33.

// Another well known theorem from elementary number theory says:

// The number of integers in the range [1, N][1,N] divisible by dd is equal to \lfloor\frac N d \rfloor⌊
// d N/d
// N
// ​
//  ⌋, where \lfloor x \rfloor⌊x⌋ is the largest integer less than xx.

// Therefore, the number of integers in the range [L, R][L,R] divisible by 33 == number of integers in the range [1,R][1,R] divisible by 33 -− number of integers in the range [1,L-1][1,L−1] divisible by 33 = \lfloor\frac R 3\rfloor -\lfloor\frac {L-1} 3\rfloor=⌊
// 3
// R
// ​
//  ⌋−⌊
// 3
// L−1
// ​
//  ⌋.

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int l, r, cnt = 0;
		cin >> l >> r;
		// long long int num = (r - l);
		// double ans = num / (double)3;
		//cout << ans << endl;
		// cnt = round(ans);
		// cout << cnt << endl;
		// for (int i = l; i <= r; i++) {
		// 	if (SOD(i) % 3 == 0)
		// 		cnt++;
		// }
		//cnt = ceil(r / 3) - ceil((l - 1) / 3);
		cnt = (r / 3) - (l - 1) / 3;
		cout << cnt << endl;
	}

	return 0;
}