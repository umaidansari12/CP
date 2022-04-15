#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void permutation(string &s, int l, int r, set<string>&perm)
{
	if (l == r)
	{
		perm.insert(s);
		return;
	}
	for (int i = l; i <= r; i++)
	{
		swap(s[l], s[i]);
		permutation(s, l + 1, r, perm);
		swap(s[l], s[i]);
	}

}

/*class Solution {
public:
	void factorial(long long int *fact, int n)
	{
		fact[0] = 1;
		fact[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			fact[i] = (i * fact[i - 1]) % 1000003;
		}
	}
	int rank(string S) {
		x
		// code here
		int n = S.size(), rank = 1;
		long long int fact[n + 1];
		factorial(fact, n);
		for (int i = 0; i < n - 1; i++)
		{
			// f/=(n-i);
			int count = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (S[j] == S[i])
					return 0;
				if (S[j] < S[i])
					count++;
			}
			rank += (count * fact[n - i - 1]) % 1000003;
		}
		return rank % 1000003;
	}
};*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		set<string> perm;
		permutation(s, 0, s.size() - 1, perm);
		//sort(perm.begin(), perm.end());
		int cnt = 0;
		for (auto i : perm)
		{
			if (i == s)
			{
				cout << cnt + 1 << "\n";
			}
			cnt++;

		}
		cout << endl;
		/*for (int i = 0; i < perm.size(); i++)
		{
			if (perm[i] == s)
			{
				cout << i + 1 << endl;
				break;
			}
		}*/

	}


	return 0;
}