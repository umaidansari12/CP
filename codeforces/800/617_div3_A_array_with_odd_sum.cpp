#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Firstly, if the array already has an odd sum, the answer is "YES". Otherwise, we need to change the parity of the sum, so we need to change the parity of some number. We can do in only when we have at least one even number and at least one odd number. Otherwise, the answer is "NO".*/

string solve()
{
	int n, sum = 0, even = 0, odd = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)//if any even number is found
			even = 1;
		else
			odd = 1;//if any odd number is found
		sum += a[i];
	}
	if (sum % 2 == 1)//if sum is already odd then we will simply return YES possily  zero number of operations
		return "YES";
	if (odd and even)// sum is even we need to make it odd then we will need to replace one even number with one odd number to make the sum odd because even + odd = odd sum odd+odd = even sum even +even == even sum and if one even and one odd is found then this operation can be performed otherwise any of them is not found then this operation cannot be performed because we cant replace odd with odd as  it yields even sum and similaryly even with even because yields even sum
		return "YES";
	return "NO";
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
		cout << solve() << endl;
	}
	/*
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		bool odd = false, even = false;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum += x;
			odd |= x % 2 != 0;
			even |= x % 2 == 0;
		}
		if (sum % 2 != 0 || (odd && even)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	*/

	return 0;
}