#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}

//You can reach the wave array by swapping the adjacent elements based on some checks.
/*This can be done in O(n) time by doing a single traversal of given array. The idea is based on the fact
that if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent odd elements, we don’t need to worry about odd positioned element. Following are simple steps.
1) Traverse all even positioned elements of input array, and do following.
….a) If current element is smaller than previous odd element, swap previous and current.
….b) If current element is smaller than next odd element, swap next and current.*/

class Solution {
public:
	void convertToWave(vector<int>& arr, int n) {
		// code here
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				if (i + 1 < n)
					swap(arr[i], arr[i + 1]);
			}
		}

	}
};

class Solution {
public:
	void convertToWave(vector<int>& arr, int n) {
		for (int i = 0; i < n - 1; i = i + 2)
			swap(arr[i], arr[i + 1]);
	}
};
