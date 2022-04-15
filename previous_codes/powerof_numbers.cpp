
using namespace std;
using ll = long long;

ll reve(ll n)
{
	string s = to_string(n);
	reverse(s.begin(), s.end());
	ll r = stoll(s, nullptr, 10);
	return r;
}

ll mod_expo(ll n, ll r)
{
	if (r == 0)
		return 1;
	if (r % 2 == 0)
	{
		ll y = mod_expo(n, r / 2);
		return (((y % 1000000007) * (y % 1000000007)) % 1000000007);
	}
	else
	{
		return ((n % 1000000007) * (mod_expo(n, r - 1) % 1000000007) % 1000000007);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll r = reve(n);
		cout << mod_expo(n, r) << endl;
	}


	return 0;
}