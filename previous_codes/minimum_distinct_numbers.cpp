#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//Remove the less frequent element first.
class Solution
{

public:
	int mindistinct(int arr[], int n, int k)
	{
		unordered_map<int, int> count;

		// Count the occurences of number
		// and store in count
		for (int i = 0; i < n; i++)
			count[arr[i]]++;

		// Count the occurences of the
		// frequencies
		vector<int> fre_arr(n + 1, 0);
		for (auto it : count) {
			fre_arr[it.second]++;
		}

		// Take answer as total unique numbers
		// and remove the frequency and
		// subtract the answer
		int ans = count.size();

		for (int i = 1; i <= n; i++) {
			int temp = fre_arr[i];
			if (temp == 0)
				continue;

			// Remove the minimum number
			// of times
			int t = min(temp, k / i);
			ans -= t;
			k -= i * t;
		}

		// Return the answer
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