/*Given two sorted arrays of size m and n of distinct elements. Given a value x. The problem is to count all pairs from both arrays whose sum is equal to x.
Note: The pair has an element from each array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers m and n denoting the size of the two arrays. The next two lines contains the two arrays arr1 and arr2 respectively. The last line contains the value of sum x.

Output:
Print the count of all pairs from both arrays whose sum is equal to x.
Input:
2
4 4
1 3 5 7
2 3 5 8
10
7 7
1 2 3 4 5 7 11
2 3 4 5 6 8 12
9

Ouput:
2
5*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solution(vector<int> a, vector<int> b, int n, int m, int x)
{
	int i = 0, j = m - 1, count = 0;
	while (i < n && j >= 0)
	{
		if (a[i] + b[j] == x)
		{
			count++;
			i++;
			j--;
		}
		else if (a[i] + b[j] > x)
		{
			j--;
		}
		else if (a[i] + b[j] < x)
		{
			i++;
		}
	}
	return count;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, x;
		cin >> n >> m;
		vector<int> a(n);
		vector <int> b(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		cin >> x;
		cout << solution(a, b, n, m, x) << endl;
	}
	return 0;
}