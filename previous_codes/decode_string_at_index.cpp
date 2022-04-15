#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Approach 1: Work Backwards
Intuition

If we have a decoded string like appleappleappleappleappleapple and an index like K = 24, the answer is the same if K = 4.

In general, when a decoded string is equal to some word with size length repeated some number of times (such as apple with size = 5 repeated 6 times), the answer is the same for the index K as it is for the index K % size.

We can use this insight by working backwards, keeping track of the size of the decoded string. Whenever the decoded string would equal some word repeated d times, we can reduce K to K % (word.length).

Algorithm

First, find the length of the decoded string. After, we'll work backwards, keeping track of size: the length of the decoded string after parsing symbols S[0], S[1], ..., S[i].

If we see a digit S[i], it means the size of the decoded string after parsing S[0], S[1], ..., S[i-1] will be size / Integer(S[i]). Otherwise, it will be size - 1.
Complexity Analysis

Time Complexity: O(N)O(N), where NN is the length of S.

Space Complexity: O(1)O(1).
*/

char decodeAtIndex(string s, int k) {
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (res.size() >= k)
			break;
		if (isalpha(s[i]))
			res += (s[i]);
		else if (isdigit(s[i]))
		{
			int n = s[i] - '0';
			//cout << n << endl;
			string r = res;
			for (int i = 1; i < n; i++)
				res += r;

		}
		//cout << res << endl;
	}
	//cout << res << endl;
	return char(res[k - 1]);
}

class Solution {
public:
	string decodeAtIndex(string S, int K) {
		long size = 0;
		int N = S.size();

		// Find size = length of decoded string
		for (int i = 0; i < N; ++i) {
			if (isdigit(S[i]))
				size *= S[i] - '0';
			else
				size++;
		}

		for (int i = N - 1; i >= 0; --i) {
			K %= size;
			if (K == 0 && isalpha(S[i]))
				return (string) "" + S[i];

			if (isdigit(S[i]))
				size /= S[i] - '0';
			else
				size--;
		}
		return "";
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		int k;
		cin >> k;
		cout << decodeAtIndex(s, k) << endl;

	}

	return 0;
}