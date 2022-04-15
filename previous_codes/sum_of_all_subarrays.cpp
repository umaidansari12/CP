/*Every number in the array at ith (1 based) position would come (i)*(n - i + 1) times.
So we have to just sum this using modulo operator.*/

//Back-end complete function template for C++

class Solution {
public:
	long long subarraySum(long long A[], long long N)
	{

		long long p = 1e9 + 7, sum = 0;
		for (long long i = 0; i < N; i++)
			sum = (sum + ((((i + 1) * A[i]) % p) * (N - i)) % p) % p;

		return sum;
	}
};

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		long long p = 1e9 + 7, sum = 0, temp = 0;
		vector<int> A(n);
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
			//sum = (sum % p + A[i] % p) % p;
		}
		for (int i = 0; i < n; i++)
		{
			temp = 0;
			for (int j = i; j < n; j++)
			{
				temp += A[j];
				sum += temp;
			}
			cout << temp << " " << sum << endl;
		}
		/*
		if(n==1)
		return a[0];
		sum = (sum * 2);
		//cout << sum << endl;
		for (int k = 2; k <= n - 1; k++)
		{
			for (int i = 0; i <= n - k; i++)
			{
				for (int j = i; j < i + k; j++)
					sum = (sum % p + A[j] % p) % p;
				// cout << sum << endl;
			}
		}*/
		cout << "------ " << sum << endl;
	}


	return 0;
}