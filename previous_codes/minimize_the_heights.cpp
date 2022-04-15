//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*The big thing to observe is that for any given tower, if you choose to increase its height from hi to hi + k,
 then you might as well increase the height of all shorter towers: that won't affect the maximum
 (because if hj < hi, then hj + k < hi + k), and may help by increasing the minimum. Conversely, if you choose
 to decrease the height of a tower from hi to hi − k, then you might as well decrease the heights of all taller
 towers.

So while there are 2n possible ways to choose which towers should be increased vs. decreased, we can actually
ignore most of these. Some tower will be the tallest tower that we increase the height of; for all shorter towers,
we will increase their height as well, and for all taller towers, we will decrease their height. So there are
only n interesting ways to choose which towers should be increased vs. decreased: one for each tower's chance to
be the tallest tower that we increase the height of.

[Pedantic note #1: You may notice that it's also valid to decrease the heights of all towers,
in which case there's no such tower. But that's equivalent to increasing the heights of all towers —
whether we add k to every height or subtract k from every height, either way we're not actually changing
the max-minus-min.]

[Pedantic note #2: I've only mentioned "shorter towers" and "taller towers", but it's also possible
that multiple towers have the same initial height. But this case isn't really important, because we might
 as well increase them all or decrease them all — there's no point increasing some and decreasing others.
  So the approach described here still works fine.]

So, let's start by sorting the original heights and numbering them in increasing order, so that h1 is
the original height of the originally-shortest tower and hn is the original height of the originally-tallest
tower.

For each i, try the possibility that the ith-shortest tower is the tallest tower that we increase the height of
; that is, try the possibility that we increase h1 through hi and decrease hi+1 through hn. There are two groups
of cases:

If i < n, then the final height of the finally-shortest tower is min(h1 + k, hi+1 − k), and the final height
of the finally-tallest tower is max(hi + k, hn − k). The final difference in this case is the latter minus
the former.
If i = n, then we've increased the heights of all towers equally, so the final
difference is just hn − h1.
We then take the least difference from all n of these possibilities.


Here's a Java method that implements this (assuming int-valued heights; note that hi is arr[i-1] and hi+1 is arr[i]):

private static int doIt(final int[] arr, final int k) {
    java.util.Arrays.sort(arr);
    final int n = arr.length;
    int result = arr[n - 1] - arr[0];
    for (int i = 1; i < n; ++i) {
        final int min = Math.min(arr[0] + k, arr[i] - k);
        final int max = Math.max(arr[n - 1] - k, arr[i - 1] + k);
        result = Math.min(result, max - min);
    }
    return result;
}
Note that I've pulled the i = n case before the loop, for convenience.
Make an array of all possible heights with the tower number, i.e. if height of any tower is h then we will insert h+k in the array and h-k.
Sort the array.
Find the index upto which height of every tower is included from the starting. Initialise the answer to the difference between height at this index and starting index.
Then with the help of two pointer technique increment the left pointer which was initially at 0 such that one of the tower is not included.
Similarly increment right pointer to make all towers included and update the answer. Do this until end of the array.
*/

class Solution {
public:
	int getMinDiff(int arr[], int n, int k) {
		// code here
		sort(arr, arr + n);
		int min_e, max_e;
		int res = arr[n - 1] - arr[0];
		for (int i = 1; i <= n - 1; i++)
		{
			max_e = max(arr[i - 1] + k, arr[n - 1] - k);
			min_e = min(arr[0] + k, arr[i] - k);
			//cout << max_e << " " << min_e << endl;
			res = min(res, max_e - min_e);
		}
		return res;
	}
	void solve(int i, int &res, int *arr, int n, int k)
	{
		if (i >= n)
			return;
		arr[i] += k;
		int ma = *max_element(arr, arr + n);
		int mi = *min_element(arr, arr + n);
		res = min(res, ma - mi);
		solve(i + 1, res, arr, n, k);
		arr[i] -= k;
		arr[i] -= k;
		ma = *max_element(arr, arr + n);
		mi = *min_element(arr, arr + n);
		res = min(res, ma - mi);
		solve(i + 1, res, arr, n, k);
		arr[i] += k;
	}
	int getMinDif(int arr[], int n, int k)
	{
		int res = INT_MAX;
		solve(0, res, arr, n, k);
		return res;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> k;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.getMinDiff(arr, n, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends