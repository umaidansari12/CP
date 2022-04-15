#include <bits/stdc++.h>

using namespace std;
using ll = long long;


/*

	Time Complexity : O(N)
	Space Complexity : O(N)

	where N is size of string of words


*/


string replaceSpacesBrute(string &str)
{
	//String to store result
	string res;

	//Variable to store length of string
	int len = str.size();

	int i = len;

	for (int i = 0; i < len; i++)
	{

		//Add "@40" in place of space
		if (str[i] == ' ')
		{
			res += "@40";
		}

		//Add character to res.
		else
		{
			res += str[i];
		}
	}

	// return res
	return res;
}

/*

	Time Complexity  : O(N)
	Space Complexity : O(1)

	where N is the size of string of words

*/


string replaceSpaces(string &str)
{
	int spaceCount = 0;

	//Count Number of Spaces
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			spaceCount = spaceCount + 1;
		}
	}

	// store thr current length of the string in a variable
	int len = str.size();

	//Find the new length
	int newLength;
	newLength = len + (spaceCount * 2);

	// resize the current string
	str.resize(newLength);

	//Index to end of string
	int index = newLength - 1;

	//Fill string from end
	for (int k = len - 1 ; k >= 0; k--)
	{
		if (str[k] == ' ')
		{
			str[index] = '0';
			str[index - 1] = '4';
			str[index - 2] = '@';
			index = index - 3;
		}
		else
		{
			str[index] = str[k];
			index = index - 1;
		}
	}

	// return string
	return str;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	/*int n, spaces, index;
	char *s1 = "Mr John Smith    ";
	//getline(cin, s1);
	//cin.ignore();
	cin >> truelength;
	/*for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' ')
			s2.append("%20");
		else
			s2 += s1[i];
	}
	cout << s2 << endl;

	for (int i = 0; i < truelength; i++)
	{
		if (s1[i] == ' ')
			spaces++;
	}
	index = truelength + spaces * 2;
	for (int i = truelength - 1; i >= 0; i--)
	{
		if (s1[i] == ' ')
		{
			s1[index - 1] = '0';
			s1[index - 2] = '2';
			s1[index - 3] = '%';
			index = index - 3;
		}
		else
		{
			s1[index - 1] = s1[i];
			index--;
		}
	}
	for (int i = 0; i < s1.length; i++)
		cout << s1[i] ;
	cout << endl;*/
	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string s;
		getline(cin, s);
		cout << replaceSpaces(s) << endl;
		continue;
		char str[1000];
		cin.get(str, 1000, '\n');
		cin.ignore();
		int truelength, i = 0, spaces = 0, index;
		cin >> truelength;
		for (i = 0; str[i]; i++)
		{
			if (str[i] == ' ')
				spaces++;
		}
		while (str[i] == ' ')
		{
			spaces--;
			i--;
		}
		index = i + spaces * 2;
		str[index--] = '\0';
		for (int j = i - 1; j >= 0; j--)
		{
			if (str[index - 1] == ' ')
			{
				str[index - 1] = '0';
				str[index - 2] = '2';
				str[index - 3] = '%';
				index = index - 3;
			}
			else
			{
				str[index - 1] = str[j];
				index--;
			}
		}
		for (int j = 0; str[j]; j++)
			cout << str[j];
		cout << endl;
	}
	return 0;
}