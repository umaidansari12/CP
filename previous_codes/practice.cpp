#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int T;
	cin >> T;
	//This program is written to show how pascal's triangle is coded in C++ programming language
	while (T--)
	{
		int n;
		cin >> n;
		/*vector<vector<int>> pascal(n);
		for (int i = 0; i < n; i++)
		{
			pascal[i].resize(i + 1); //as every ith row of pascal's triangle contains (i+1) element
			pascal[i][0] = pascal[i][i] = 1;//first and last element of every row contains 1
			for (int j = 1; j < i; j++)
			{
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];//As every element is the sum
				// of previous element i.e just above the current element i.e pascal[i][j] and its one element back
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < pascal[i].size(); j++)
			{
				cout << pascal[i][j] << " ";
			}
			cout << endl;
		}*/
		vector<long long int> pascal(n, 1);
		int c = 1;
		for (int i = 1; i < n; i++)
		{
			c *= (n - i);
			cout << c << " ";
			c /= (i);
			cout << c << endl;
			pascal[i] = c;
		}
		for (int i = 0; i < n; i++)
			cout << pascal[i] << " ";
		cout << endl;


	}

	return 0;
}