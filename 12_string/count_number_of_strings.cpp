//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
	long long int substrCountBrute (string s, int k) {
		//code here.
		int n = s.size(), count = 0;
		for (int i = 0; i < n; i++) {
			unordered_map<char, int> m;
			for (int j = i; j < n; j++) {
				m[s[j]]++;
				if (m.size() == k)
					count++;
				if (m.size() > k)
					break;
			}
		}
		return count;
	}
	long long int substrCount_Brute (string s, int k) {
		//code here.
		int n = s.size(), answer = 0;
		for (int i = 0; i < n; i++) {
			unordered_map<char, int> m;
			int count = 0;
			for (int j = i; j < n; j++) {
				m[s[j]]++;
				if (m[s[j]] == 1)
					count++;
				if (count == k)
					answer++;
				if (count > k)
					break;
			}
		}
		return answer;
	}
	long long int substrCount (string s, int k) {
		//code here.
		return atMostK(s, k) - atMostK(s, k - 1);
	}
	long long int atMostK(string s, int k) {
		long long int ans = 0;
		int n = s.size(), start = 0;
		int count[26] = {0};
		for (long long int end = 0; end < n; end++) {
			if (!count[s[end] - 'a']++)
				k--;
			while (k < 0) {
				if (!--count[s[start] - 'a'])
					k++;
				start++;
			}
			ans += (end - start + 1);
		}
		return ans;
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