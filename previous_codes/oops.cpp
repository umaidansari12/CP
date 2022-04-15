#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Test
{
	const int i;
public:
	Test(int x): i(x)
	{
		cout << "\ni value set: " << i;
	}
};

int main()
{
	Test t(10);
	t.i = 20;
	Test s(20);
}

/*int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	return 0;
}*/