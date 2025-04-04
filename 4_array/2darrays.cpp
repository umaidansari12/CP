#include<bits/stdc++.h>
using namespace std;
void print(int a[10][], int n, int m)
{
	for (int i = 0; n > i; i++)
	{
		for (int j = 0; m > j; j++)
		{
			cout << a[i] << a[j] << " ";
		}
		cout << endl;
	}

}
int main()
{


	int a[10][10];
	int n, m;
	cin >> n >> m;
	for (int i = 0; n > i; i++)
	{
		for (int j = 0; m > j; j++)
		{
			cin >> a[i][j];
		}
	}
	print(a, n, m);
	return 0;

}