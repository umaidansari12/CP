#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*The idea is to process all digits one by one
and use the property that xy (mod a) ≡ ((x (mod a) * y) (mod a))*/

class Solution
{

public:
	int xmod11(string x)
	{
		int len = x.length();

		int num, rem = 0;

		for (int i = 0; i < len; i++) {
			num = rem * 10 + (x[i] - '0');
			rem = num % 11;
		}

		return rem;

	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}