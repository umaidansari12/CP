#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> fizzbuzz(int n) {
	vector<string> res;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			res.push_back("FizzBuzz");
		else if (i % 5 == 0)
			res.push_back("Buzz");
		else if (i % 3 == 0)
			res.push_back("Fizz");
		else
			res.push_back(to_string(i));
	}

	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> r = fizzbuzz(n);
	for (string s : r)
		cout << s << ",";
	cout << endl;


	return 0;
}