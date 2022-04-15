/***Fate whispers to warrior "You cannnot withstand the storm" and the warrior whispers back "I am the Storm"***/

#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long double ldl;


#define INF 0x3f3f3f3f
#define MOD 1e9+7
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
#define pl pair<lli,lli>
#define vi vector<int>
#define mii map<int,int>
#define vp vector<pair< int,int> >
#define vl vector<lli>
#define mll map<lli,lli>
#define vpl vector<pair< lli,lli> >
#define endl "\n"
#define afill(A,x) memset(A,x,sizeof A);
#define vfill(A,x) fill(A.begin(), A.end(), x);
#define rep(i,k,n) for(int i = k; i < n; i++)
#define per(i,k,n) for(int i = k; i >= n; i--)
#define repp(i,a,n,k) for(int i=a;i!=n;i+=k)
#define setbits(x) __builtin_popcountll(x)
#define debug(a) cout<<#a<<": ";for(int i:a)cout<<i<<" ";cout<<'\n';
#define lb lower_bound
// lowerbound to return min iterator of element if present else return next grater element
#define ub upper_bound
// upperfound return first value greater than element and last if no element


//powermod
lli powermod(lli x, lli y, lli m)
{
    lli res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}


//combination work

void initFact(lli *fact, lli *invfact, lli n, lli mod) {
    fact[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    invfact[n] = powermod(fact[n], mod - 2, mod);
    for (long long i = n - 1; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
    return;
}

int choose(lli x, lli y, lli fact[], lli invfact[], lli mod)
{
    //call initFact once before using this any time
    // return yCx or choose x from y
    return (x > y ? 0 : fact[y] * invfact[x] % mod * invfact[y - x] % mod);
}

//fibbonacci

void fibMultiply(lli F[2][2], lli M[2][2], lli m)
{
    lli x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    lli y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    lli z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    lli w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x % m;
    F[0][1] = y % m;
    F[1][0] = z % m;
    F[1][1] = w % m;
}


void fibPower(lli F[2][2], lli n, lli m)
{
    if (n == 0 || n == 1)
        return;
    lli M[2][2] = {{1, 1}, {1, 0}};

    fibPower(F, n / 2, m);
    fibMultiply(F, F, m);

    if (n % 2 != 0)
        fibMultiply(F, M, m);
}

lli fib(lli n, lli m)
{
    lli F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    fibPower(F, n - 1, m);

    return F[0][0];
}



//graphs

void readGraphWeighted(vp *adj, int m) {
    int u, v, w;
    rep(i, 0, m) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
}

void readGraph(vp *adj, lli m) {
    lli u, v;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));
    }
}


//dijkstra with par and dist arr to return
void dijkstra(vpl *adj, lli src, vl &dist, vl &par)
{
    priority_queue< pl, vp , greater<pl> > pq;
    vfill(dist, INF);
    vfill(par, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        lli u = pq.top().ss;
        pq.pop();

        vpl::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            lli v = (*i).ff;
            lli weight = (*i).ss;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                par[v] = u;
            }
        }
    }
}


//read
void readN(auto *A, int n) {
    rep(i, 0, n) {
        cin >> A[i];
    }
}



/**coding region **/

//define global var here



//pre calc to be done here

void pre() {

}

//reset for each test case to be done here

void reset() {

}


//solver for each test case

void solve() {
    //code here
    lli l, r;
    lli mod = 99991;
    cin >> l >> r;
    cout << fib(r + 2, mod) - fib(l + 1, mod);
    return;
}


int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(0);
//  cout.tie(0);
    // Comment above for interative or any other required case where buffering is not required


    pre();

    int t;
    //cin>>t;
    t = 1; // use this if no t
    rep(i, 0, t) {
        reset();
        solve();
    }
    return 0;
}

/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;                                     // Reading input from STDIN
    cout << "Input number is " << num << endl;      // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

long long MOD = 99991;

int main()
{
    int period = 33330;
    int fib[period];
    fib[0] = 0; fib[1] = 1;
    long long sum2 = 1;
    for (int i = 2; i < period; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        sum2 += fib[i];
        sum2 %= MOD;
    }
    long long l, r;
    cin >> l >> r;
    long long  sum1 = 0;
    while (l <= r)
    {
        if (l % period == 0)
            break;
        sum1 += fib[l % period];
        sum1 %= MOD;
        l++;
    }
    while (r >= l)
    {
        if (r % period == 0)
            break;
        sum1 += fib[r % period];
        sum1 %= MOD;
        r--;
    }
    sum1 += (((r - l + 1) % MOD) * sum2) % MOD;
    sum1 %= MOD;
    cout << sum1 << endl;
}

#include<bits/stdc++.h>
using namespace std;

long long MOD = 99991;

int main()
{
    int period = 33330;
    int fib[period];
    fib[0] = 0; fib[1] = 1;
    long long sum2 = 1;
    for (int i = 2; i < period; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        sum2 += fib[i];
        sum2 %= MOD;
    }
    long long l, r;
    cin >> l >> r;
    long long  sum1 = 0;
    while (l <= r)
    {
        if (l % period == 0)
            break;
        sum1 += fib[l % period];
        sum1 %= MOD;
        l++;
    }
    while (r >= l)
    {
        if (r % period == 0)
            break;
        sum1 += fib[r % period];
        sum1 %= MOD;
        r--;
    }
    sum1 += (((r - l + 1) % MOD) * sum2) % MOD;
    sum1 %= MOD;
    cout << sum1 << endl;
}

/*'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
def fibsum(L , R):

    arr = []
    arr.append(0)
    arr.append(1)
    sum1 = 0
    for i in range(2 , R):
        arr.append(arr[i-1] + arr[i-2])

    for k in range(L , R):
        sum1 += arr[k]
    return sum1
name = input()
for i in range(min(int(name) , 100)):
    nums = input()
    a , b = nums.split(" ")
    print(fibsum(int(a) , int(b)))
*/