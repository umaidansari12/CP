#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int max_TrailingDifference(vector<int>s, int n)
{
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			res.push_back(s[i] - s[j]);
		}
	}
	res.push_back(-1);
	return *max_element(res.begin(), res.end());
}

int maxTrailingDifference(vector<int>s, int n)
{
	int max1 = INT_MIN, max_index = -1;
	int min1 = INT_MAX, min_index = -1;
	for (int i = 0; i < n; i++)
	{
		if (max1 < s[i])
		{
			max1 = s[i];
			max_index = i;
		}
	}
	//cout << "MAX : " << max1 << " " << max_index << endl;
	int m = -1;
	/*for (int i = 0; i < max_index; i++)
	{
		if (min1 > s[i])
		{
			min1 = s[i];
			min_index = i;
		}
	}*/
	for (int i = 0; i < max_index; i++)
	{
		m = max(m, s[max_index] - s[i]);
	}
	//cout << "MIN : " << min1 << " " << min_index << endl;
	//return (min_index == max_index) ? -1 : max1 - min1;
	return m;
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
		int n;
		cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		cout << maxTrailingDifference(s, n) << endl;
	}


	return 0;
}