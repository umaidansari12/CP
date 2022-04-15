#include<bits/stdc++.h>
using namespace std;



string normalize(const string &sentence) {
	string copy = sentence;
	//Make the changes in copy, and return it
	transform(copy.begin(), copy.end(),	copy.begin(), ::tolower);
	//cout << copy << endl;
	for (int i = 0; i < copy.size(); i++)
	{
		if (i == 0)
		{
			copy[i] = toupper(copy[i]);
		}
		if (copy[i - 1] == ' ')
			copy[i] = toupper(copy[i]);
	}


	return copy;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		cout << normalize(s) << endl;
	}
}