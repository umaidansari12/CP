#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{

		string A, B;
		cin >> A >> B;
		int n = A.size(), m = B.size(), f = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				swap(A[i], A[j]);
				if (A.compare(B) == 0)
				{
					cout << "True\n";
					f = 1;
					break;
				}
				swap(A[i], A[j]);
			}
		}
		if (f == 0)
			cout << "False\n";

	}


	return 0;
}