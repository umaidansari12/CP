#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int smallestWindowBrute(string s)
{
	int n = s.size(), ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		string s1;
		int count[3] = {0};
		for (int j = i; j < n; j++)
		{
			s1 += s[j];
			count[s[j] - '0']++;
			if (count[0] >= 1 and count[1] >= 1 and count[2] >= 1)
				ans = min(ans, j - i + 1);
			//cout << s1 << endl;
		}
	}
	return ans == INT_MAX ? -1 : ans;
}

int smallestWindowOptimal(string s)
{
	int n = s.size(), ans = INT_MAX, i = 0, j = 0;
	int count[3] = {0};
	while (j < n)
	{
		count[s[j] - '0']++;
		while (count[0] >= 1 and count[1] >= 1 and count[2] >= 1)
		{
			ans = min(ans, j - i + 1);
			count[s[i] - '0']--;
			i++;
		} x
		j++;
	}
	return ans == INT_MAX ? -1 : ans;
}

int smallestWindowOptimal(string s)
{
	int n = s.size(), ans = INT_MAX, i = 0, j = 0, lastZero = -1, lastOne = -1, lastTwo = -1;
	while (j < n)
	{
		if (s[j] == '0')
			lastZero = j;
		else if (s[j] == '1')
			lastOne = j;
		else
			lastTwo = j;
		if (lastZero != -1 and lastOne != -1 and lastTwo != -1)
		{
			ans = min(ans, j - min(lastZero, min(lastOne, lastTwo)) + 1);
		}
		j++;
	}
	return ans == INT_MAX ? -1 : ans;
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
		string s;
		cin >> s;
		cout << smallestWindow(s) << endl;
	}


	return 0;
}