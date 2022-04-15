#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;

    scanf("%d",&n);

    vector<long long> v;
    long long x;
    for(int i=0;i<n;i++)
    {
            scanf("%lld",&x);
            v.push_back(x);
    }

    sort(v.rbegin(),v.rend());

    long long int sig=1;

    while(sig<=v[0])
    sig<<=1;

    sig>>=1;

    for(int t=0;sig>=1;sig>>=1)
    {
            int i=t;

            while(i<n && (v[i]&sig)==0)
            i++;

            if(i>=n)
            continue;

            swap(v[t],v[i]);

            for(int j=0;j<n;++j)
            {
                    if(j!=t && (v[j]&sig)!=0)
                    v[j]=v[j]^v[t];
            }

            t++;

    }

    long long int result=0;

    for(int q=0;q<n;q++)
    {
            result=result^v[q];
    }

    printf("%lld\n",result);

    system ("pause");

    return 0;
}*/



int check_bit(ll n, int pos)
{
	return (n & (1 << pos));
}
void solve()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	ll ans = 0;
	ll ind = 0;
	for (int bit = log2(a[0]); bit >= 0; bit--)
	{
		ll x = ind;
		while (x < n && check_bit(a[x], bit) == 0)
			x++;
		if (x == n)
			continue;
		swap(a[ind], a[x]);
		for (int j = 0; j < n; j++)
		{
			if (j != ind && check_bit(a[j], bit))
				a[j] ^= a[ind];
		}
		ind++;
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, ans ^ a[i]);

	cout << ans << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}