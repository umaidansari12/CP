/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <stdio.h>
#define SIZE 1000001
int main(void){
    int T, i, j, k, t, count;
    int *sieve_arr = ( int * ) calloc( SIZE , sizeof( int ));
    long long int sum, num;

  /*  finding all the prime no.'s upto upper bound i.e., 10^6
    by making an array of 10^6 entries where index can be treated as a no.
    except 0 and 1
    if a number is a prime number then the value at its index will be zero!!
for (i = 2; i * i < SIZE; i++)
	for (j = 2 * i; j < SIZE; j += i)
		sieve_arr[j]++;

scanf("%d", &T);

while (T--) {
	count = sum = 0;
	scanf("%d%d", &t, &k);

	while (t--) {
		scanf("%lld", &num);

		if (num > 1 && sieve_arr[num] == 0)
			//check for prime number at an index
			count++;

		if (count - k == 0) {
			sum += num;
			count = 0;
		}
	}
	printf("%lld\n", sum);
}

return 0;
}

#define MAX 1000000

bool prime[MAX + 1];


int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;
	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
				prime[j] = false;
		}
	}
	while (T--)
	{
		int n, k, c = 0;
		long long sum = 0;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (prime[a[i]])
			{
				c++;
				if (c % k == 0)
				{
					sum += a[i];
					c = 0;
				}
			}
		}
		cout << sum << endl;

	}


	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001
int main(void) {
	int T, i, j, k, t, count;
	int *sieve_arr = ( int * ) calloc( SIZE , sizeof( int ));
	long long int sum, num;

	/*  finding all the prime no.'s upto upper bound i.e., 10^6
	  by making an array of 10^6 entries where index can be treated as a no.
	  except 0 and 1
	  if a number is a prime number then the value at its index will be zero!!*/
	for (i = 2; i * i < SIZE; i++)
		for (j = 2 * i; j < SIZE; j += i)
			sieve_arr[j]++;

	scanf("%d", &T);

	while (T--) {
		count = sum = 0;
		scanf("%d%d", &t, &k);

		while (t--) {
			scanf("%lld", &num);

			if (num > 1 && sieve_arr[num] == 0)
				//check for prime number at an index
				count++;

			if (count - k == 0) {
				sum += num;
				count = 0;
			}
		}
		printf("%lld\n", sum);
	}

	return 0;
}