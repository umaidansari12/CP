s#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestUniqueSubsttr(string S) {
	//code
	int n = S.size(), ans = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		map<char, int> m;
		for (int j = 0; j < n; j++)
		{
			if (m.find(S[j]) == m.end())
			{
				m[S[j]] = 1;
				ans = max(ans, j - i + 1);
			}
			else
				break;
		}
	}
	return ans;

}

//O(N) approach

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), ans = 0;
		int l = 0, r = 0;
		map<char, int> m;
		while (r < n)
		{
			if (m.find(s[r]) != m.end())
			{
				l = max(l, m[s[r]] + 1);
			}
			m[s[r]] = r;
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), ans = 0;
		int l = 0, r = 0;
		vector<int> m(256, -1);
		while (r < n)
		{
			if (m[s[r]] != -1)
			{
				l = max(l, m[s[r]] + 1);
			}
			m[s[r]] = r;
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};



int longestUniqueSubstr(string S) {
	/*int n = S.size(), ans = 0;
	int l = 0, r = 0;
	map<int, int> m;
	while (r < n && l < n)
	{
		if (m.find(S[r]) == m.end())//m.find() will give wrong answer

		{
			ans = max(ans, r - l + 1);
			m[S[r++]]++;
		}
		else
		{
			m[S[l++]]--;
			ans = max(ans, r - l + 1);
			m[S[l]]++;
		}
	}
	return ans;*/

	int n = S.size(), ans = 0;
	int l = 0, r = 0;
	map<char, int> m;
	while (r < n && l < n)
	{
		if (m[S[r]] == 0)
		{
			ans = max(ans, r - l + 1);
			m[S[r++]]++;
		}
		else
		{
			m[S[l++]]--;
			/*ans = max(ans, r - l + 1);
			m[S[l]]++;*/
		}
	}
	return ans;
}











//Think about the sliding window technique.

class Solution {
public:
	int largestsubstring(string s) {

		int n = s.size();

		int res = 0; // result

		// last index of all characters is initialized
		// as -1
		vector<int> lastIndex(256, -1);

		// Initialize start of current window
		int i = 0;

		// Move end of current window
		for (int j = 0; j < n; j++) {

			// Find the last index of s[j]
			// Update i (starting index of current window)
			// as maximum of current value of i and last
			// index plus 1
			i = max(i, lastIndex[s[j]] + 1);

			// Update result if we get a larger window
			res = max(res, j - i + 1);

			// Update last index of j.
			lastIndex[s[j]] = j;
		}
		return res;


	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n == 0)
			return 0;
		int i = 0, j = 0, ans = 1; //initially window is of size 1 ans is 1 i.e window size 1
		vector <int> cnt(300, 0);  //maintaining count on every window size
		cnt[s[0]]++;//since window is of size 1 we increment the count of first character
		while (j != n - 1)
		{
			if (cnt[s[j + 1]] == 0) //if next element is nnot present we increment the window size
			{
				j++;
				cnt[s[j]]++;//setting the count of the current eement i.e next elemt in wndow
				ans = max(ans, j - i + 1); //maintaining local maxima in every window size
			}
			else
			{
				cnt[s[i]]--;//if cnt of next  element is there then we decrement window size
				i++;
			}
		}
		return ans;

	}
};

int longestSubstringWithoutRepeat(string s)
{
	int n = s.size();
	if (n == 0)
		return 0;
	int i = 0, j = 0, ans = 1;
	vector<int> cnt(300, 0);
	cnt[s[0]]++;
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
			cnt[s[i++]]--;
		}
	}
	return ans;
}

void printlongestSubstringWithoutRepeat(string s)
{
	int i = 0, j = 0, ans = 1, start = 0, n = s.size();
	vector<int> cnt(326, 0);
	cnt[s[0]]++;
	while (j != n - 1)
	{
		if (cnt[s[j + 1]] == 0)
		{
			j++;
			cnt[s[j]]++;
			if (ans < (j - i + 1))
			{
				ans = j - i + 1;
				start = i;
			}
		}
		else
		{
			cnt[s[i++]]--;
		}
	}
	for (int i = start; i < start + ans; i++)
	{
		cout << s[i];
	}
	cout << endl;
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
		printlongestSubstringWithoutRepeat(s);
	}


	return 0;
}