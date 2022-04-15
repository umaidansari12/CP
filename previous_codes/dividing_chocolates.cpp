#include <bits/stdc++.h>
using namespace std;

string dividingChocolate(vector<int>& chocolates) {
	int n = chocolates.size(), sum = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[chocolates[i]]++;
		sum += chocolates[i];
	}
	if ((m[100] % 2 == 0) && (m[200] % 2 == 0))
		return "Yes";
	else if (((m[100] % 2) != 0) && ((m[200] % 2) != 0))
		return "No";
	// else if(()||())
	// else if ((sum - (100 * m[100])) == (m[200] * 200))
	// 	return "Yes3";
	// return "No4";
	return "No";
}


int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		int n;
		cin >> n;
		vector<int> chocolates(n);
		for (int i = 0; i < n; i++)
		{
			cin >> chocolates[i];
		}
		string result = dividingChocolate(chocolates);
		cout << result << endl;
	}
}