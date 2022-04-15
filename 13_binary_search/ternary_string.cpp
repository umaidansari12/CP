#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool isValid(int k, string st)
{
	int ar[4] = {0};
	for (int i = 0; i < k - 1; i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;
	}

	for (int i = k - 1; i < st.size(); i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;

		if ((ar[1] > 0) && (ar[2] > 0) && (ar[3] > 0))
			return true;

		idx = st[i - k + 1] - '0';
		ar[idx]--;
	}

	return false;
}

int getAns(string st)
{
	int res = INT_MAX;
	int L = 3;
	int R = st.size();

	while (L <= R)
	{
		int mid = (L + R) / 2;

		if (isValid(mid, s))
			res = min(res , mid) , R = mid - 1;
		else
			L = mid + 1;
	}

	if (res == INT_MAX) return 0;
	else		   return res;
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

		cout << getAns(s) << '\n';
		// int count[4] = {0};
		// int i = 0, n = s.size(), j = 0, ans = INT_MAX;
		// while (j < n)
		// {
		// 	count[s[j] - '0']++;

		// 	while (count[1] >= 1 and count[2] >= 1 and count[3] >= 1 and i < n)
		// 	{
		// 		count[s[i] - '0']--;
		// 		ans = min(ans, j - i + 1);
		// 		i++;
		// 	}

		// 	j++;

		// }
		// if (ans == INT_MAX)
		// 	cout << 0 << endl;
		// else
		// 	cout << ans << endl;
	}


	return 0;
}

