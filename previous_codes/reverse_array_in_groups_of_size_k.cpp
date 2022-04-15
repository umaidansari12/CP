#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:

	void reverseInGroups(vector<long long>& arr, int n, int k) {
		// code here

		for (int i = 0; i < n; i += k)
		{
			int low = i, high = min((i + k) - 1, n - 1);
			while (low < high)
				swap(arr[low++], arr[high--]);

		}
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<long long> v(n)
	}


	return 0;
}