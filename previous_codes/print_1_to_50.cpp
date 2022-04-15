#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 50; i++)
	{
		int mod3 = i % 3, mod5 = i % 5;
		// if (i % 3 == 0 and i % 5 == 0)
		// 	cout << "FizzBuzz ";
		if (i % 3 == 0)
		{
			if (mod5 == 0)
				cout << "FizzBuzz	";
			else
				cout << "Fizz" << " ";
		}
		else if (i % 5 == 0)
		{
			if (mod5 == 0)
				cout << "FizzBuzz	";
			else
				cout << "Fizz" << " ";
		}
		else
			cout << i << " ";
	}
	cout << endl;


	return 0;
}

15 -> 3 * 5 -> fizzbuzz
