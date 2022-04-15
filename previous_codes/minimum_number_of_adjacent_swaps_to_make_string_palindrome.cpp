#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Use 2 pointer approach.

/*
Maintain 2 pointers one at the start (p1) and another at the end of string (p2).
If s[p1] == s[p2] we just increment p1 and decrement p2.
If s[p1] != s[p2]
find the nearest match k from p1 or p2 (whichever is minimum) , swap characters till k
 and increase count with every swap. Increment p1 and decrement p2.
 */

class Solution
{

public:
	int minswaps(string s)
	{
		vector<int> cc(26, 0);

		for (char c : s)
			cc[c - 'a']++;

		int flag = 0;
		for (int i = 0 ; i < 26 ; i++)
			flag += (cc[i] & 1);

		if (flag > 1) {
			return -1;
		}

		int end = s.length() - 1, ans = 0;
		for (int i = 0 ; i < s.length() / 2 ; i++) {
			if (s[i] == s[end - i])
				continue;

			int j, k;
			for (j = i + 1 ; j <= end - i && s[j] != s[end - i] ; j++);
			for (k = end - i - 1; k >= i && s[k] != s[i] ; k--);

			ans += min(j - i, end - i - k);
			if ( j - i < end - i - k) {
				for (int p = j; p > i ; p--)
					swap(s[p], s[p - 1]);
			} else {
				for (int p = k ; p < end - i ; p++)
					swap(s[p], s[p + 1]);
			}
		}
		return ans;


	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}