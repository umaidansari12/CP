#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string reverseWord(string str) {
	//Your code here
	string s;
	for (int i = str.size() - 1; i >= 0; i--)
		s += str[i];
	return s;
}

string reverseWord(string str) {
	//Your code
	int l = 0, r = str.size() - 1;
	while (l <= r)  //while(l<r)
	{
		swap(str[l++], str[r--]);
	}
	return str;
}

string reverseWord(string str) {

	//Your code here
	int n = str.size() / 2;
	for (int i = 0, j = str.size() - 1; i <= n && j >= n; i++, j--)
	{
		swap(str[i], str[j]);
	}
	return str;
}

void solve(string &str, int l, int r)
{
	if (l >= r)
		return ;
	swap(str[l], str[r]);
	solve(str, l + 1, r - 1);
}

string reverseWord(string str) {

	//Your code here
	int l = 0, r = str.size() - 1;
	solve(str, l, r);
	return str;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}