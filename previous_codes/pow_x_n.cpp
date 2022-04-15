#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int Solution::pow(int x, int n, int d) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (d == 1) return 0;
	if (x == 0) return 0;
	long long ans = 1, y = x % d;

	while (n > 0) {
		if (n & 1) ans = ((ans) * y) % d;
		y = (y * y) % d;
		if (y < 0) y += d;
		n = n >> 1; //faster than n--
		//n--;
	}
	if (ans < 0) {
		ans = (d - abs(ans) % d);
		return ans;
	}
	return ans;

}


class Solution {
public:
	double myPow(double x, int n) {
		long long int t = n;
		if (t < 0)
			t = t * (-1);
		double pro = 1;
		while (t > 0)
		{
			if (t % 2 == 0)
			{
				x *= x;
				t /= 2;
			}
			else
			{
				pro = x * pro;
				t = t - 1;
			}
		}
		if (n < 0)
			pro = (double)1.0 / (double)pro;
		return pro;

	}
};

class Solution {
public:
	double pow(double x, int n)
	{
		if (n == 0)
			return 1;
		if (n % 2 == 0)
		{
			double y = pow(x, n / 2);
			return y * y;
		}
		else
		{
			return (double)x * pow(x, n - 1);
		}

	}
	double myPow(double x, int n) {
		int t = n;
		if (n < 0)
			n = n * (-1);
		double pro = pow(x, n);
		if (t < 0)
			pro = (double)1.0 / (double)(pro);
		return pro;

	}
};

double myPow(double x, int n) {
	int t = n;
	if (n < 0)
		n = n * (-1);
	double pro = 1.0;
	for (int i = 0; i < n; i++)
	{
		pro *= x;
	}
	if (t < 0)
		pro = (double)1.0 / (double)(pro);
	return pro;

}

double myPow(double x, int n) {
	long nn = n;
	double ans = 1.0;
	if (nn < 0) nn = -1 * nn;
	while (nn > 0)
	{
		if (nn % 2 == 1)
		{
			ans = ans * x;
			nn = nn - 1;
		}
		else
		{
			x = x * x;
			nn = nn / 2;
		}
	}
	if (n < 0) ans = (double)(1.0) / (double)(ans);
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}