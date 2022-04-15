#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int a[1000000], pre[1000000];
	int n, q, m;
	cin >> n >> m >> q;
	long long int pro = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0)
			pre[i] = (a[i]) % m;
		else
			pre[i] = (a[i] * pre[i - 1]) % m;
	}
	vector<long long int> ans;
	while (q--)
	{
		int x;
		cin >> x;
		long long int an = (long long int)pre[n - 1] / (long long int)a[x - 1];
		ans.push_back(an % m);
	}
	for (auto i : ans)
		cout << i << "\n";


	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void scanint(ll *x)
{
    register char c = getchar_unlocked();
    *x = 0;
    for(;c<48 || c>57;c=getchar_unlocked());
    for(;c>47 && c<58;c=getchar_unlocked())
    *x = (ll)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

int main()
{
    ll n,m,q;
    scanint(&n),scanint(&m),scanint(&q);
    ll pror[n],prol[n],a[n];
    for(int i=0;i<n;i++)
        scanint(&a[i]);
    prol[0]=a[0];
    pror[n-1]=a[n-1];

    for(int i=1;i<n;i++)
        prol[i]=(prol[i-1]*a[i])%m;
    for(int i=n-2;i>=0;i--)
        pror[i]=(pror[i+1]*a[i])%m;

    while(q--)
    {
        ll i;
        scanint(&i);
        i--;
        if(i==0)
        printf("%lld\n",pror[1]);
        else if(i==n-1)
        printf("%lld\n",prol[n-2]);
        else
        printf("%lld\n",(prol[i-1]*pror[i+1])%m);
    }
    return 0;
}
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*#include <stdio.h>
int main()
{
	int n, m, q, i, index, product;
	scanf("%d %d", &n, &m);
	int a[n];
	scanf("%d", &q);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int prev[n], next[n];
	prev[0] = 1;
	next[n - 1] = 1;
	for (i = 1; i < n; i++)
		prev[i] = (a[i - 1] * prev[i - 1]) % m;
	for (i = n - 2; i >= 0; i--)
		next[i] = (a[i + 1] * next[i + 1]) % m;
	while (q--)
	{
		scanf("%d", &index);
		int product = (prev[index - 1] * next[index - 1]) % m;
		printf("%d\n", product);
	}
	return 0;
}
Language: C*/