#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool checkSubset(string s1, string s2)
{
	int i = s1.size() - 1, j = s2.size() - 1;
	while (i >= 0 && j >= 0)
	{
		if (s2[j] == s1[i])
		{
			i--;
			j--;
		}
		else
			i--;
	}
	if (j == -1)
		return true;
	return false;
}

bool isSubSequence(string A, string B)
{
	// code here
	int j = 0;
	for (int i = 0; i < B.size() && j < A.size(); i++)
	{
		if (A[j] == B[i])
			j++;
	}
	return j == A.size();
}

/*bool checkSubset(string s1,string s2)
{
	for(int i=0;i<s1.size();i++)
		m[s1[i]]++;
	for(int i=0;i<s2.size();i++)
		if(m[s2[i]])
}
*/
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
		string s1, s2;

		getline(cin, s1, '\n');
		//cin.ignore();
		getline(cin, s2, '\n');
		//cin.ignore();
		cout << s1 << " " << s2 << endl;
		if (checkSubset(s1, s2))
			cout << "yes\n";
		else
			cout << "no\n";
	}


	return 0;
}