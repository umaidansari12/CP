#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	long long int a[n] = {0};
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (q--) {
		long long int l, r, x, cnt = 0;
		cin >> l >> r >> x;
		// for (int i = l - 1; i < r; i++)
		// {
		// 	if (a[i] >= x)
		// 		cnt++;
		// }
		// cout << cnt << endl;
		if ((lower_bound(a, a + n, x) - a) == n)
			cout << "0\n";
		else {
			long long int idx = lower_bound(a + l - 1, a + r - 1, x) - a;
			cout << r - idx << endl;
		}
		// if (idx == n)
		// 	cout << 0 << endl;
		// else {
		// 	//cout << idx << " ";
		// 	if (idx > (l - 1))
		// 		cout << (n - idx - 1) - (n - r - 1) << endl;
		// 	else
		// 		cout << n - (l - 1) - (n - r - 1) << endl;
		// }

// 		def bi(arr,f,r,c):
//     low =f
//     h=r
//     h1=r-1
//     mid = 0
//     while low <= h1:
//         mid=(low+h1)//2
//         if arr[mid]>=c:
//             h=mid
//             h1=mid-1
//         else:
//             low=mid+1
//     return h
// x,y=map(int,input().split())
// l=list(map(int,input().split()))
// for i in range(y):
//     f,r,c=map(int,input().split())
//     ind=bi(l,f-1,r,c)
//     print(r-ind)# cook your dish here



	}

	return 0;
}