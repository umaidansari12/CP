#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Constraints are small.
Use Dynamic Programming to find the size of the smallest subset whose XOR is i*/


class Solution {
public:
	int smallestSubsetMaxOR(int N, vector<int> A)
	{
		int mx = 0; //It will store the maximum possible OR
		for (auto i : A)
			mx |= i;

		vector<int> v(mx + 1, -1);
		v[0] = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = mx; j >= 0; j--)
			{
				if (v[j] != -1 && (j | A[i]) <= mx)
				{
					if (v[j | A[i]] == -1)
						v[j | A[i]] = 1 + v[j];
					else
						v[j | A[i]] = min(v[j | A[i]], 1 + v[j]);
				}
			}
		}

		return v[mx];
	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}