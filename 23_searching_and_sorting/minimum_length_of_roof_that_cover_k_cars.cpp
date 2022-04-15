#include <bits/stdc++.h>

using namespace std;
using ll = long long;


/*

2
4 3
12 6 5 2
5 5
12 3 8 6 13
*/

/*
You are given an List of positions of cars as to where they are parked. You are also given an integer K.
 The cars needs to be covered with a roof. You have to find the minimum length of roof that takes to cover K cars.

 Input : 12,6,5,2      K = 3

 Explanation :  There are two possible roofs that can cover K cars. One that covers the car in 2,5,6 parking spots and
 another roof which covers 5,6,12 parking spots. The length of these two roofs are 5 and 8 respectively. Return 5
 since that's the roof with minimum length that covers K cars.

 Output : 5
*/


// Input : 12, 6, 5, 2 , 1  K = 3
//                              0   1  2  3   4
//                              5	6			12 -> 8

//                              1 2 5 6 12  K = 3

int minLength(int a[], int n, int k) {
	sort(a, a + n);
	if (n == 0 or n < k)
		return 0;
	// for (int i = 0; i < n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	int ans = INT_MAX;
	for (int i = 0; i < (n - k + 1); i++) {
		ans = min(ans, (a[(i + k) - 1] - a[i]) + 1);
	}
	return ans;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << minLength(a, n, k) << endl;
	}


	return 0;
}