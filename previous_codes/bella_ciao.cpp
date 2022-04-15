#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*#include <bits/stdc++.h>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	#define fr(n) for(ll i=0; i<n; i++)
	#define ch cout<<endl
	using namespace std;
	void solve(){

		ll D,d,p,q,cnt = 0;
		ll x,y;
		cin>>D>>d>>p>>q;
		x = D/d;

		if(x%2==0){
			cnt += d * ((x/2) * (2*p+(x-1) * q));
		}
		else{
			cnt += d * (x*(p+((x-1) /2 ) * q));
		}
		cnt += (D%d) * (p + (x) * q);

		cout<<cnt<<endl;




	}

	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		ll T;
		cin>>T;
		//cin.ignore(); //must be there when using getline(cin, s)
		while(T--)
		{
			solve();
		}
		return 0;
	}*/

long long int solve(long long int d, long long int D, long long int P, long long int Q)
{
	long long int days = D / d, result = 0, rate = 0;
	if ((D % d) != 0)
		days++;
	//cout << days << endl;
	for (int i = 0; i < days; i++)
	{
		if (D >= d)
			result += (d * (P + (rate * Q)));
		else
			result += (D * (P + (rate * Q)));
		D = D - d;
		rate++;
	}
	return result;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		long long int d, D, P, Q, result = 0, rate = 0;
		cin >> D >> d >> P >> Q;
		if (D <= 3 or (D / d) == 0)
			result = d * (P + ((D / d) * Q));
		else if ((D / d) != 0)
			result = d * (P + ((D / d) - 1) * Q) + (D % d) * (P + ((D / d)) * Q) + d;
		cout << result << endl;
	}


	return 0;
}