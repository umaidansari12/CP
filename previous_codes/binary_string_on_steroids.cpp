#include <bits/stdc++.h>
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

#define pb push_back
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll total_0 = 0, total_1 = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') {
            total_1++;
        }
        else {
            total_0++;
        }
    }
    vll factors;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                factors.push_back(i);
            }
            else {
                factors.push_back(n / i);
                factors.push_back(i);
            }
        }
    }
    ll res = 1e9;
    for (auto fact : factors) {
        vector<ll> freq(fact);
        for (ll i = 0; i < fact; i++) {
            for (ll j = i; j < n; j += fact) {
                if (s[j] == '1') {
                    freq[i]++;
                }
            }
        }
        ll req = n / fact;
        for (ll i = 0; i < fact; i++) {
            ll ap = req - freq[i];
            ap += (total_1 - freq[i]);
            res = min(res, ap);
        }

    }
    cout << res << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}