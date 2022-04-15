#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Use greedy approach. Put the highest frequency character first and then use Binary
 Max Heap where all characters are ordered by their frequencies such that the highest
  frequency character is the root.
One by one take the highest frequency character from the heap and add it to result.
Once added, decrease frequency of the character and temporarily move this
character out of Max Heap so that it is not picked again.
*/

class Solution
{

public:
	const int MAX_CHAR = 26;
	struct Key
	{
		int freq; // store frequency of character
		char ch;
		bool operator<(const Key &k) const
		{
			return freq < k.freq;
		}
	};
	string solve(string str)
	{
		int n = str.length();
		int count[MAX_CHAR] = {0};
		for (int i = 0 ; i < n ; i++)
			count[str[i] - 'a']++;
		priority_queue< Key > pq;
		for (char c = 'a' ; c <= 'z' ; c++)
			if (count[c - 'a'])
				pq.push( Key { count[c - 'a'], c} );
		str = "" ;
		Key prev { -1, '#'} ;
		while (!pq.empty())
		{
			Key k = pq.top();
			pq.pop();
			str = str + k.ch;
			if (prev.freq > 0)
				pq.push(prev);
			(k.freq)--;
			prev = k;
		}
		if (n != str.length())
			return "-1";
		else
			return str;
	}

	bool rearrangeString(string S)
	{
		string str = solve(S);
		if (str == "-1")
			return false;
		for (int i = 0; i < str.length(); i++)
		{
			if (i > 0)
				if (str[i - 1] == str[i])
					return false;
		}
		return true;
	}
};
class Solution
{
public:
	bool rearrangeString(string S)
	{
		//code here
		unordered_map<char, int> freq;
		int max_freq = 0;
		for (int i = 0; i < S.size(); i++)
		{
			freq[S[i]]++;
			max_freq = max(max_freq, freq[S[i]]);
		}
		if (max_freq <= (S.size() - max_freq + 1))
			return true;
		return false;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}