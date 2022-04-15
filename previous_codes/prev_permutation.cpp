#include<bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r, vector<string>&re)
{
	if (l == r)
	{
		re.push_back(s);
		return;
	}
	for (int j = l; j <= r; j++)
	{
		swap(s[l], s[j]);
		permute(s, l + 1, r, re);
		swap(s[l], s[j]);
	}
}
// C++ program to print all permutations with
// duplicates allowed using prev_permutation()

// Function to compute the previous permutation
bool prevPermutation(string& str)
{
	// Find index of the last element of the string
	int n = str.length() - 1;

	// Find largest index i such that str[i - 1] >
	// str[i]
	int i = n;
	while (i > 0 && str[i - 1] <= str[i])
		i--;

	// if string is sorted in ascending order
	// we're at the last permutation
	if (i <= 0)
		return false;

	// Note - str[i..n] is sorted in ascending order

	// Find rightmost element's index that is less
	// than str[i - 1]
	int j = i - 1;
	while (j + 1 <= n && str[j + 1] < str[i - 1])
		j++;

	// Swap character at i-1 with j
	swap(str[i - 1], str[j]);

	// Reverse the substring [i..n]
	reverse(str.begin() + i, str.end());

	return true;
}
// C++ program to print all permutations with
// duplicates allowed using prev_permutation()
#include <bits/stdc++.h>
using namespace std;

// Function to compute the previous permutation
bool prevPermutation(string& str)
{
	// Find index of the last element of the string
	int n = str.length() - 1;

	// Find largest index i such that str[i - 1] >
	// str[i]
	int i = n;
	while (i > 0 && str[i - 1] <= str[i])
		i--;

	// if string is sorted in ascending order
	// we're at the last permutation
	if (i <= 0)
		return false;

	// Note - str[i..n] is sorted in ascending order

	// Find rightmost element's index that is less
	// than str[i - 1]
	int j = i - 1;
	while (j + 1 <= n && str[j + 1] < str[i - 1])
		j++;

	// Swap character at i-1 with j
	swap(str[i - 1], str[j]);

	// Reverse the substring [i..n]
	reverse(str.begin() + i, str.end());

	return true;
}

// Driver code
int main()
{
	string str = "4321";
	if (prevPermutation(str))
		cout << "Previous permutation is " << str;
	else
		cout << "Previous permutation doesn't exist";
	return 0;
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
		vector<string> res;
		permute(s, 0, s.size() - 1, res);
		sort(res.begin(), res.end());
		/*for (auto i : res)
			cout << i << " ";
		cout << endl;*/
		int idx = lower_bound(res.begin(), res.end(), s) - res.begin();
		if (idx  == 0)
			cout << -1 << endl;
		else
			cout << res[idx - 1] << endl;
	}


	return 0;
}