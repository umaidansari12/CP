#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {

public:
	long long ValidPair(int a[], int n)
	{
		// Your code goes here
		sort(a, a + n);
		int l = 0;
		int h = n - 1;
		long long ans = 0;
		while (l < h) {
			if (a[l] + a[h] > 0) {
				ans += h - l;
				h--;
			}
			else
				l++;
		}
		return ans;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}