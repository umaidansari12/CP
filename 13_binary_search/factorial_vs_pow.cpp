#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double f[10000005];




// int a ;
// scanf("%d", &a);


// printf("%d\n", n);
// }
// return 0;
// }


void factorial()
{
	//f[0] = 1;
	f[1] = log10(1.0);
	for (int i = 2; i <= 10000000; i++)
	{
		f[i] = f[i - 1] + log10((double)i);
	}
	// for (auto i : f)
	// 	cout << i << " ";
	// cout << endl;
}

ll fact(ll n)
{
	return f[n];
}

double g(ll a, int n)
{
	//return pow(a, n);
	return (double)n * log10(a);
}

ll BSearch(ll a)
{
	int lo = 1 , hi = 10000000 , n = -1 ;

	while ( lo <= hi )
	{
		int mid = (lo + hi) / 2 ;
		double fi = f[mid] ;
		double g = (double)mid * log10(a);
		if (fi > g)
		{
			n = mid ;
			hi = mid - 1 ;
		}
		else lo = mid + 1 ;
	}
	return n;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	factorial();
	int t;
	cin >> t;
	while (t--)
	{
		ll a, ans = 0;
		cin >> a;
		// for (int  n = 1; n <= 10000000; n++)
		// {
		// 	if ((double)fact(n) > (double)g(a, n))
		// 	{
		// 		ans = n;
		// 		break;
		// 	}
		// }
		// cout << ans << endl;
		cout << BSearch(a) << endl;
	}


	return 0;
}