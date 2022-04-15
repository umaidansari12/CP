#include <bits/stdc++.h>

using namespace std;
using ll = long long;


/*
The maximum sum we can construct with n elements is 1+3+5+7+⋯+2n−1=n2, so we
need at least ⌈s√⌉ elements to construct the sum equal to s. Let's show how
to express s with exactly ⌈s√⌉ elements.

Let ⌈s√⌉=d. By taking 1+3+5+7+⋯+2d−3, we achieve a sum of (d−1)2 using d−1
elements. s−(d−1)2 is not less than 1 and not greater than 2d−1 (since
(d−1)2−−−−−−−√=d−1, and (d−1)2+2d−−−−−−−−−−−√>d). Thus, we can just add s−
(d−1)2 to our array, and the sum becomes exactly s.

So, the solution is to find the minimum n such that n2≥s.
*/
int solve()
{
	int s;
	cin >> s;
	return ceil(sqrt(s));
	int count = 0, place = 1;
	while (s > 0)
	{
		s -= place;
		count++;
		place += 2;
	}
	// int count = 1;
	// int max = 1;
	// int val = 1;
	// while (max < s)
	// {
	// 	val += 2;
	// 	count++;
	// 	max += val;
	// }
	return count;
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
		cout << solve() << endl;
	}


	return 0;
}