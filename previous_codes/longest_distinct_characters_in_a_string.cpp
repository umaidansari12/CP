#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool areDistinct(string s, int i, int j, int n)
{
	vector<bool> cnt(300, false);
	for (int k = i; k <= j; k++)
	{
		if (cnt[s[k]] == true)
			return false;
		cnt[s[k]] = true;
	}
	return true;

}

void brute(string s, int n)
{
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (areDistinct(s, i, j, n))
				ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
}

void slidWin(string s, int n)
{
	int ans = INT_MIN;
	vector<bool> cnt(300, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (cnt[s[j]] == true)
				break;
			else
			{
				ans = max(ans, j - i + 1);
				cnt[s[j]] = true;
			}
		}
		cnt[s[i]] = false;
	}
	cout << ans << endl;
}

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
		slidWin(s, s.size());
		/*vector<int> cnt(300, 0);
		int i = 0, j = 0, ans = INT_MIN, n = s.size();
		cnt[s[i]]++;
		while (j != n - 1)
		{
			if (cnt[s[j + 1]] == 0)
			{
				j++;
				cnt[s[j]]++;
				ans = max(ans, j - i + 1);
			}
			else
			{
				cnt[s[i]]--;
				i++;
			}

		}
		cout << ans << endl;*/

	}


	return 0;
}