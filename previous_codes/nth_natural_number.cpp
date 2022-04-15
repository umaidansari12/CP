#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*If you remove all the 9s from a sequence of numbers in base 10, then you end up with a sequence in base 9.

So all we have to do is convert n in base 10, to base 9 and return that.


int nthNumber(int n) {
    return Integer.valueOf(Integer.toString(n, 9));
}
- Blackbird June 10, 2017 | FlagReply
0
of 0 vote
Cost O(nlogn). The operation of computing if a number contains a 9 is logarithmic as we check each digit we perform this operation n times.
Solution in Python:


def contains9(n):
    while (n > 10):
        if (n % 10) == 9: return True
        n /= 10
    if n == 9: return True
    return False

def filter9(n):
    return filter(lambda x: not contains9(x),
                    xrange(1, n+1))*/

long long findNth(long long N)
{
	// code here.
	long long int c = 0, n = 1;
	while (c < N)
	{
		if (n % 9 != 0)
			c++;
		n++;
	}
	return n - 1;

}
long long findNth1(long long N)
{
	long long ans = 0;
	int i = 0;
	while (N) {
		ans += (pow(10, i) * (N % 9));
		N /= 9;
		i++;
		cout << ans << " " << N << endl;
	}
	return ans;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		cout << findNth1(n) << endl;
	}


	return 0;
}