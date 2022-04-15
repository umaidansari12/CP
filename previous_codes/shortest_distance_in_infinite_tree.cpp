#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*If you observe the pattern carefully you can move up the tree from a given node by dividing the node no by 2.
 thus incrementing the length by 1.
You can follow similar approach to solve this particular problem by maintaing 2 such values for the two given
node numbers x and y and iterate and count the values untill both becomes equal to each other.*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, count = 0;
		cin >> x >> y;
		while (x != y)
		{
			if (x > y)
			{
				x /= 2;
				count++;
			}
			if (y > x)
			{
				y /= 2;
				count++;
			}
		}
		cout << count << endl;

	}


	return 0;
}