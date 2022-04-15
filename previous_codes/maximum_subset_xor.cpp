#include <bits/stdc++.h>

using namespace std;
using ll = long long;



class Solution
{
public:

	int check_bit(int n, int pos)
	{
		return (n & (1 << pos));
	}
	int maxSubarrayXOROptimal(int arr[], int N)
	{
		//Your code here
		sort(arr, arr + N, greater<int>());
		int ind = 0;
		for (int bit = log2(arr[0]); bit >= 0; bit--)
		{
			int x = ind;
			while (x < N && check_bit(arr[x], bit) == 0)
				x++;
			if (x == N)
				continue;
			swap(arr[ind], arr[x]);
			for (int j = 0; j < N; j++)
			{
				if (ind != j && check_bit(arr[j], bit))
					arr[j] ^= arr[ind];
			}
			ind++;
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
			ans = max(ans, ans ^ arr[i]);
		return ans;
	}
}

string getBinaryString(int i, int n)
{
	string s;
	int c = 0;
	while (i > 0)
	{
		s += (to_string(i % 2));
		i /= 2;
		c++;
	}
	while (c < n)
	{
		s += '0';
		c++;
	}
	reverse(s.begin(), s.end());
	return s;
}
int maxSubarrayXORBrute(int arr[], int N)
{
	//Your code here
	int ans = INT_MIN;
	for (int i = 1; i <= pow(2, N) - 1; i++)
	{
		string binaryString = getBinaryString(i, N);
		int xr = 0;
		for (int i = 0; i < binaryString.size(); i++)
		{
			if (binaryString[i] == '1')
				xr ^= (arr[i]);
		}
		ans = max(xr, ans);
	}
	return ans;
}
int maxSubarrayXOR(int set[], int n)
{
	//Your code here
	int index = 0;

	// Traverse through all
	// bits of integer
	// starting from the most
	// significant bit (MSB)
	for (int i = 32 - 1; i >= 0; i--)
	{
		// Initialize index of
		// maximum element and
		// the maximum element
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			// If i'th bit of set[j]
			// is set and set[j] is
			// greater than max so far.
			if ( (set[j] & (1 << i)) != 0
			        && set[j] > maxEle )
				maxEle = set[j], maxInd = j;
		}

		// If there was no
		// element with i'th
		// bit set, move to
		// smaller i
		if (maxEle == INT_MIN)
			continue;

		// Put maximum element
		// with i'th bit set
		// at index 'index'
		swap(set[index], set[maxInd]);

		// Update maxInd and
		// increment index
		maxInd = index;

		// Do XOR of set[maxIndex]
		// with all numbers having
		// i'th bit as set.
		for (int j = 0; j < n; j++)
		{
			// XOR set[maxInd] those
			// numbers which have the
			// i'th bit set
			if (j != maxInd &&
			        (set[j] & (1 << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}

		// Increment index of
		// chosen elements
		index++;
	}

	// Final result is
	// XOR of all elements
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}
};

// { Driver Code Starts.
int main()
{

	int t, n, a[100004], k;
	scanf("%d", &t);
	while (t--)
	{
		//cin>>n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		Solution obj;
		printf("%d\n", obj.maxSubarrayXORBrute(a, n));
		// cout<<bin(a,0,n-1,k)<<endl;
	}
}  // } Driver Code Ends