
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	static bool comp(char a, char b) {
		return (int)a > (int)b;
	}
	string findMax(string N) {
		// code here
		sort(N.begin(), N.end(), comp);
		return N;
	}
	string findMax(string N) {
		// code here
		int freq[10] = {0};
		for (int i = 0; i < N.size(); i++) {
			freq[N[i] - '0']++;
		}
		string s;
		for (int i = 9; i >= 0; i--) {
			while (freq[i]--) {
				s += (i + '0');
			}
		}
		return s;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		string N;

		cin >> N;

		Solution ob;
		cout << ob.findMax(N) << endl;
	}
	return 0;
}  // } Driver Code Ends