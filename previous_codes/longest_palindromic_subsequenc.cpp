#include <bits/stdc++.h>
/*
If L(i,j) (i>=j) denotes the length of longest palindromic subsequence present in S[i..j] then

L(i,j) = L(i+1,j-1) + 2 if S[i] and S[j] are same,
otherwise L(i,j)  = max(L(i+1,j),L(i,j-1)).
*/


using namespace std;
using ll = long long;

class Solution1
{
public:
	int lps1(string seq, int i, int j)
	{
		// Base Case 1: If there is only 1 character
		if (i == j)
			return 1;

		// Base Case 2: If there are only 2
		// characters and both are same
		if (seq[i] == seq[j] && i + 1 == j)
			return 2;

		// If the first and last characters match
		if (seq[i] == seq[j])
			return lps1 (seq, i + 1, j - 1) + 2;

		// If the first and last characters do not match
		return max( lps1(seq, i, j - 1), lps1(seq, i + 1, j) );
	}
	int lps(string str)
	{
		//code here
		int n = str.size();
		int i, j, cl;
		int L[n][n];  // Create a table to store results of subproblems


		// Strings of length 1 are palindrome of lentgh 1
		for (i = 0; i < n; i++)
			L[i][i] = 1;

		// Build the table. Note that the lower diagonal values of table are
		// useless and not filled in the process. The values are filled in a
		// manner similar to Matrix Chain Multiplication DP solution (See
		// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
		// substring
		for (int cl = 2; cl <= n; cl++)
		{
			for (int i = 0; i < n - cl + 1; i++)
			{
				j = i + cl - 1;
				if (str[i] == str[j] && cl == 2)
					L[i][j] = 2;
				else if (str[i] == str[j])
					L[i][j] = L[i + 1][j - 1] + 2;
				else
					L[i][j] = max(L[i][j - 1], L[i + 1][j]);
			}
		}

		return L[0][n - 1];
	}
};

class Solution
{
public:
	int lps(string S)
	{
		int n = S.size();
		int dp[n][n];

		// gap=0;
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;

		// gap=1;
		for (int i = 0; i < n - 1; i++)
			if (S[i] == S[i + 1])
				dp[i][i + 1] = 2;
			else
				dp[i][i + 1] = 1;

		for (int gap = 2; gap < n; gap++)
			for (int i = 0; i < n - gap; i++)
				if (S[i] == S[i + gap])
					dp[i][i + gap] = 2 + dp[i + 1][i + gap - 1];
				else
					dp[i][i + gap] = max( dp[i + 1][i + gap] , dp[i][i + gap - 1] );

		return dp[0][n - 1];
	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}