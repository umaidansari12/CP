//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
	long long int substrCountBrute(string s, int k) {
		//code here.
		long long int cnt = 0;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			map<char, int> m;
			for (int j = i; j < n; j++)
			{
				m[s[j]]++;
				if (m.size() == k)
					cnt++;
			}
		}
		return cnt;
	}
	long long int substrCount(string s, int k) {
		//code here.
		long long int greater = atMostK(s, k);
		long long int smaller = atMostK(s, k - 1);
		return greater - smaller;
	}
	long long int atMostK(string s, int k) {
		long long int i = 0, res = 0;
		int count[26] = {0};
		for (long long int j = 0; j < s.size(); j++) {
			if (!count[s[j] - 'a']++)
				k--;
			while (k < 0) {
				if (!--count[s[i] - 'a'])
					k++;
				i++;
			}
			res += (j - i + 1);
		}
		return res;
	}
};

// { Driver Code Starts.


int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout << ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends