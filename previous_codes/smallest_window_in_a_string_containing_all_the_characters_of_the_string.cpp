#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string smallestWindowBrute(string l, string s)
{
	//cout << l << " " << s << endl;
	unordered_map<char, int> m1;
	for (int i = 0; i < s.length(); i++)
		m1[s[i]]++;
	int min_window_len = INT_MAX, start_window = -1;
	for (int i = 0; i < l.length(); i++)
	{
		for (int j = i; j < l.length(); j++)
		{
			unordered_map<char, int> m2;
			string s2 = l.substr(i, j - i + 1);
			//cout << s2 << endl;
			bool found = true;
			for (int k = 0; k < s2.length(); k++)
			{
				m2[s2[k]]++;
			}
			for (int k = 0; k < s.length(); k++)
			{
				if (m1[s[k]] > m2[s[k]])
					found = false;
			}
			if (found)
			{
				if (min_window_len > (j - i + 1))
				{
					min_window_len = j - i + 1;
					start_window = i;
				}
			}
		}
	}
	return l.substr(start_window, min_window_len);
}


string smallestWindow(string s, string p)
{
	int FS[256] = {0};
	int FP[256] = {0};
	for (int i = 0; i < p.length(); i++)
		FP[p[i]]++;
	int cnt = 0, start = 0, window_size = 0, min_window_len = INT_MAX, start_idx = -1;
	for (int i = 0; i < s.length(); i++)
	{
		FS[s[i]]++;
		if (FP[s[i]] != 0 and FS[s[i]] <= FP[s[i]])
		{
			cnt++;
		}
		if (cnt == p.size())
		{
			while (FP[s[start]] == 0 or FS[s[start]] > FP[s[start]])
			{
				FS[s[start++]]--;
			}
			window_size = i - start + 1;
			if (min_window_len > window_size)
			{
				min_window_len = window_size;
				start_idx = start;
			}
		}
	}
	if (start_idx == -1)
		return "No window found";
	return s.substr(start_idx, min_window_len);
}

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
		string l, s;
		getline(cin, l);
		getline(cin, s);
		cout << smallestWindow(l, s) << endl;

	}


	return 0;
}