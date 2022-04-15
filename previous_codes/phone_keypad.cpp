#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void generatePhoneNumber(vector<int> arr, int n, int i, vector<string>&phoneNumber, string s, unordered_map<int, string> &m)
{
	if (i == n)
	{
		phoneNumber.push_back(s);
		return;
	}
	for (auto j : m[arr[i]])
	{
		generatePhoneNumber(arr, n, i + 1, phoneNumber, s + j, m);
	}
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	unordered_map<int, string> m;
	m[2] = "ABC";
	m[3] = "DEF";
	m[4] = "GHI";
	m[5] = "JKL";
	m[6] = "MNO";
	m[7] = "PQRS";
	m[8] = "TUV";
	m[9] = "WXYZ";
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<string> phoneNumber;
		generatePhoneNumber(a, n, 0, phoneNumber, "", m);
		for (auto i : phoneNumber)
			cout << i << "\n";
		cout << endl;


	}


	return 0;
}