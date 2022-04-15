#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	vector<ll> nthRowOfPascalTriangle(int n) {
		// code here
		vector<ll> pascal(n + 1);
		int mod = 1e9 + 7;
		pascal[0] = 1;
		for (int i = 0; i <= n; i++)
		{
			for (int j = i; j > 0; j--)
			{
				pascal[j] = (pascal[j - 1] + pascal[j]) % mod;
			}
		}
		return pascal;
	}
};


vector<int> Solution::getRow(int A) {
	vector<int> pascal(A + 1, 1);
	int res = 1;
	for (int i = 1; i < A; i++)
	{
		res *= (A - i + 1);
		res /= i;
		pascal[i] = res;
	}
	return pascal;
}

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vi(rowIndex + 1);
		vi[0] = 1;
		for (int i = 0; i <= rowIndex ; ++i)
		{
			for (int j = i; j > 0; --j)
			{
				vi[j] = vi[j] + vi[j - 1];
			}
		}
		return vi;
	}
};
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		/*vector<vector<int>> pascal(26);
		for (int i = 0; i < 26 ; i++)
		{
			pascal[i].resize(i + 1);
			pascal[i][0] = pascal[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}
		}
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < pascal[i].size() ; j++)
			{
				cout << pascal[i][j] << " ";
			}
			cout << endl;
		}*/
		vector<int> pascal(n);
		int c = 1;
		pascal[0] = pascal[n - 1] = 1;
		for (int i = 1 ; i < n; i++)
		{
			c *= (n - i);
			c /= (i);
			pascal[i] = c;
		}
		for (int i = 0; i < n; i++)
		{
			cout << pascal[i] << " ";
		}
		cout << endl;
	}



	return 0;
}