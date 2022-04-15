#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string smallestWindowVague(string str) {
	//Complete this method
	int data[256] = {0};
	int start = 0, end = 0;

	for (int i = 0; i < str.size(); i++) {
		data[str[i]]++;

		if (data[str[i]] == 1) {
			end = i;
		} else if (str[start] == str[i]) {
			data[str[start]]--;
			start++;
			while (data[str[start] > 1]) {
				data[str[start]]--;
				start++;
			}
		}
	}

	return str.substr(start, end - start + 1);
}

class Solution {
public:
	string findSubString(string s)
	{
		// Your code goes here
		int cnt[256] = {0}, cnt1[256] = {0}, count = 0, count1 = 0, start = 0, window_len = 0, min_window_len = INT_MAX, start_idx = -1;
		for (int i = 0; i < s.length(); i++)
		{
			cnt[s[i]]++;
			if (cnt[s[i]] == 1)
				count++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			cnt1[s[i]]++;
			if (cnt[s[i]] != 0 && cnt1[s[i]] == 1)
				count1++;
			if (count == count1)
			{
				while (cnt1[s[start]] > 1)
				{
					cnt1[s[start++]]--;
				}
				window_len = i - start + 1;
				if (window_len < min_window_len)
				{
					min_window_len = window_len;
					start_idx = start;
				}
			}
			//cout << count1 << endl;
		}
		//cout << count << endl;
		return s.substr(start_idx, min_window_len);
	}
};


string smallestWindowBrute(string s) {
	//Complete this method
	unordered_map<char, int> m;
	for (int i = 0; i < s.size(); i++)
		m[s[i]]++;
	//cout << m.size() << endl;
	int min_window_len = INT_MAX, window_len = 0, start = -1;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			unordered_map<char, int> m1;
			window_len = j - i + 1;
			string s2 = s.substr(i, j - i + 1);

			for (int k = 0; k < s2.size(); k++)
				m1[s2[k]]++;
			if (m.size() == m1.size())
			{
				if (min_window_len > window_len)
				{
					min_window_len = window_len;
					start = i;
				}
			}
		}
	}
	return s.substr(start, min_window_len);
}

string smallestWindow(string s)
{
	int cnt[256] = {0}, cnt1[256] = {0}, count = 0, count1 = 0, start = 0, window_len = 0, min_window_len = INT_MAX, start_idx = -1;
	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i]]++;
		if (cnt[s[i]] == 1)
			count++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		cnt1[s[i]]++;
		if (cnt[s[i]] != 0 && cnt1[s[i]] == 1)
			count1++;
		if (count == count1)
		{
			while (cnt1[s[start]] > 1)
			{
				cnt1[s[start++]]--;
			}
			window_len = i - start + 1;
			if (window_len < min_window_len)
			{
				min_window_len = window_len;
				start_idx = start;
			}
		}
		//cout << count1 << endl;
	}
	//cout << count << endl;
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
		string s;
		getline(cin, s);
		cout << smallestWindow(s) << endl;
	}


	return 0;
}