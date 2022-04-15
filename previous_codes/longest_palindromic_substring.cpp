#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*The idea is to generate all
even length and odd length palindromes and keep track of the longest palindrome seen so far.


To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes,
 i.e. fix i (index) as center and two indices as i1 = i+1 and i2 = i-1.

For generating even length palindrome ,Take two indices i1 = i and i2 = i-1
and compare characters at i1 and i2 and find the maximum length till all pair of
compared characters are equal and store the maximum length.

*/

class Solution {
public:
	string longestPalindrome(string A) {

		int i, high, low, len, start = 0, max = 1, even = 0;
		len = A.size();
		if (len % 2 == 0) {
			even = 1;
		}
		for (i = 1; i < len; i++) {
			low = i - 1;
			high = i;
			while (low >= 0 && high < len && A[low] == A[high]) {
				if (high - low + 1 > max) {
					max = high - low + 1;
					start = low;
				}
				--low;
				++high;
			}
			low = i - 1;
			high = i + 1;
			while (low >= 0 && high < len && A[low] == A[high]) {
				if (high - low + 1 > max) {
					max = high - low + 1;
					start = low;
				}
				--low;
				++high;
			}
		}
		return A.substr(start, max);
	}
};
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		/*for (int i = 0; i < s.length(); i++)
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[i] == s[j])
				{
					int k = i, m = j;
					while (k < m)
					{
						if (s[k] != s[m])
							break;
					}
				}
			}
		}*/
		int mx = 0, start = -1;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				//
				int flag = 1;
				for (int k = 0; k < (j - i + 1) / 2; k++)
				{
					if (s[i + k] != s[j - k])
						flag = 0;
				}
				if (flag && (j - i + 1) > mx)
				{
					cout << i << " " << j << endl;
					start = i;
					mx = j - i + 1;
				}
			}
		}
		for (int i = start; i <= (start + mx) - 1; i++)
			cout << s[i];
		cout << endl;
	}


	return 0;
}


class Solution {
public:
	int expand(string &s, int l, int h)
	{
		int n = s.size();
		while (l >= 0 && h <= n - 1 && s[l] == s[h])
		{
			l--;
			h++;
		}
		return h - l - 1;
	}
	string longestPalindrome(string s) {
		if (s.size() <= 1)
			return s;
		int st = 0, en = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int len1 = expand(s, i, i);
			int len2 = expand(s, i, i + 1);
			int len = max(len1, len2);
			if (len > (en - st))
			{
				st = i - ((len - 1) / 2);
				en = i + (len / 2);
			}
		}

		return s.substr(st, en - st + 1);
	}
};
class Solution {
public:
	string expand(string &s, int l, int h)
	{
		int n = s.size();
		while (l >= 0 && h <= n - 1 && s[l] == s[h])
		{
			l--;
			h++;
		}
		return s.substr(l + 1, h - l - 1);
	}
	string longestPalindrome(string s) {
		if (s.size() <= 1)
			return s;
		string l = s.substr(0, 1);
		for (int i = 0; i < s.size(); i++)
		{
			string temp = expand(s, i, i);
			if (l.size() < temp.size())
				l = temp;
			temp = expand(s, i, i + 1);
			if (l.size() < temp.size())
				l = temp;
		}

		return l;
	}
};