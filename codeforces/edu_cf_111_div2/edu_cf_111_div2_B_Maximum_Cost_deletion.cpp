#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Let l1,l2,…,lk be the length of the substring deleted at the i-th step. Then
the number of points will be equal to ∑i=1k(a⋅li+b) or a∑i=1kli+bk. The sum
of all li is equal to n (because in the end we deleted the entire string), so
the final formula has the form an+bk. Obviously, for b≥0, you should delete
the characters one by one so that k=n. Now b<0 and you have to delete the
string in the minimum number of operations. Let the string s consist of m
blocks of zeros and ones, then ⌊m2⌋+1 is the minimum number of operations for
which the entire string can be deleted. As long as the number of blocks is
more than 2, we will delete the second block, the number of blocks will
decrease by 2 after each such operation (the block that we delete will
disappear, and the first and third blocks will merge into one).
*/


int solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int ans = n * a;
	if (b >= 0)
	{
		ans += (n * b);
		return ans;
	}
	else
	{
		// int count = 1;
		// for (int i = 1; i < n; i++)
		// {
		// 	if (s[i] != s[i - 1])
		// 		count++;
		// }
		// ans += (count / 2 + 1 ) * b;
		int zeroCount = 0 , onesCount = 0;
		char last = 'a';
		for (auto c : s)
		{
			if (c == last)
				continue;
			last = c;
			if (c == '0')
				zeroCount++;
			else
				onesCount++;
		}
		ans += min(1 + zeroCount, 1 + onesCount) * b;
	}
	return ans;
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