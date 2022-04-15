#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	int findPairs(long long a[], long long n)
	{
		//code here.
		// solution is not corret for the test case {20 20 7 16 6}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int l = k + 1; l < n; l++) {
						//cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << endl;
						if ((a[i] + a[j]) == (a[k] + a[l]) or ((a[i] + a[k]) == (a[j] + a[l])) or ((a[i] + a[l]) == (a[j] + a[k])))
						{
							ans = 1;
							//cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << endl;
						}

					}
				}

			}
		}
		return ans;
	}
	int findPairs(long long a[], long long n)
	{
		//code here.
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++) {
				if (m[a[i] + a[j]]) {
					return 1;
				}
				else {
					m[a[i] + a[j]]++;
				}
			}
		}
		return 0;
	}
};

// { Driver Code Starts.
int main() {
	long long t;

	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		long long a[n];
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
			// um[a[i]]++;
		}
		Solution ob;
		cout << ob.findPairs(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends