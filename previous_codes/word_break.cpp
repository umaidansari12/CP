//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> dict;
		for (int i = 0; i < n; i++) {
			string S;
			cin >> S;
			dict.push_back(S);
		}
		string line;
		cin >> line;
		cout << wordBreak(line, dict) << "\n";
	}
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings
bool dictContains(vector<string> &dict, string prefix)
{
	for (int i = 0; i < dict.size(); i++)

	{	if (dict[i].compare(prefix) == 0)
			return true;
	}
	return false;
}

int wordBreak(string A, vector<string> &B) {
	//code here
	int s = A.size();
	if (s == 0)
		return 1;
	for (int i = 1; i <= s; i++)
	{
		if (dictContains(B, A.substr(0, i)) && wordBreak(A.substr(i, s - i), B))
			return 1;
	}
	return 0;

}