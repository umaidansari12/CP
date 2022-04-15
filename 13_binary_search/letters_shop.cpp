#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int n, m;
string s, t;

int countoft[26] = {0};

vector<int> countofs[26];//2d array stoting the every index of every characters present in string s

bool isValid(int idx, int * countoft)
{
	int countofs[26] = {0};
	for (int i = 0; i <= idx; i++)
		countofs[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (countofs[i] < countoft[i])
			return false;
	return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s >> m;
	//cout << n << " " << s << " " << m << endl;

	for (int i = 0; i < n; i++)
		countofs[s[i] - 'a'].push_back(i);
	while (m--)
	{
		cin >> t;
		memset(countoft, 0, sizeof(countoft));
		int ans = 0;
		for (int i = 0; i < t.size(); i++)
			countoft[t[i] - 'a']++;
		for (int i = 0; i < 26; i++)
		{
			if (countoft[i]) //means if this character is contained in the string t then our answer will be the max of last index of every character present in string s
			{
				ans = max(ans, countofs[i][countoft[i] - 1] + 1); //taking into consideration last occurrence of ith character from s with respect to t;
				//s : arrayhead
				// t: arya  // at 0 in countofs 0 : 0 3 7 this will be present and in t a occurs only 2 time so we go to the 2nd index where a is present to take the last index of a when count of a in t is 2
			}
		}
		cout << ans << endl;
		// int countoft[26] = {0};
		// for (int i = 0; i < t.size(); i++)
		// 	countoft[t[i] - 'a']++;
		// int low = t.size() - 1, high = n - 1, ans = INT_MAX, mid;
		// while (low <= high)
		// {
		// 	mid = low + (high - low) / 2;
		// 	if (isValid(mid, countoft))
		// 	{
		// 		ans = mid;
		// 		high = mid - 1;
		// 	}
		// 	else
		// 		low = mid + 1;
		// }

		//cout << t << endl;
		// for (int i = t.size() - 1; i < n; i++)
		// {
		// 	if (isValid(i, countoft))
		// 	{
		// 		cout << i + 1 << '\n';
		// 		break;
		// 	}
		// }
	}

	return 0;
}