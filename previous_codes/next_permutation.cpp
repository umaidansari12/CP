#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Find the first pair of two consecutive numbers perm[i] and perm[i-1] , from the end, which satisfy perm[i]>perM[i−1].
 Now, no rearrangements to the right of perm[i−1] can create a greater permutation since that subarray consists of numbers
 in descending order. The only task remaining is to rearrange the numbers to the right of perm[i-1] including itself.


 Step 1: Find the largest index k, such that perm[k]<perm[k+1]

Step 2: Find the largest index l, such that perm[l]>perm[k].

Step 3: Swap perm[k] and perm[l].

Step 4: Reverse from perm[k+1] to the end.

*/

vector<int> nextPermutation1(vector<int> &A) {

	int n = A.size(), ind1 = n - 2;
	while (ind1 >= 0 && A[ind1] > A[ind1 + 1])
		ind1--;
	if (ind1 < 0)
		reverse(A.begin(), A.end());
	else
	{
		int ind2 = n - 1;
		while (ind2 > ind1 && A[ind2] <= A[ind1])
		{
			ind2--;
		}
		swap(A[ind1], A[ind2]);
		reverse(A.begin() + ind1 + 1, A.end());
	}
	return A;
}

class Solution {
public:
	void nextPermutation(int perm[], int N) {
		int i = N - 2;
		while (i >= 0 && perm[i + 1] <= perm[i]) {
			i--;
		}
		if (i >= 0) {
			int j = N - 1;
			while (j >= 0 && perm[j] <= perm[i]) {
				j--;
			}
			swap(perm[i], perm[j]);
		}
		i++;
		int end = N - 1;
		while (i < end)
		{swap(perm[i], perm[end]); i++; end--;}


	}
};

void nextPermutation(vector<int>& nums) {
	//next_permutation(nums.begin(),nums.end());
	/*if(nums.empty() ||nums.size()==1)
	    return;*/
	int n = nums.size();
	int ind1 = n - 2;
	for (ind1 = n - 2; ind1 >= 0; ind1--)
	{
		if (nums[ind1] < nums[ind1 + 1])
		{
			break;
		}
	}
	if (ind1 < 0)
		reverse(nums.begin(), nums.end());
	else
	{
		int ind2 = n - 1;
		for (ind2 = n - 1; ind2 > ind1; ind2--)
		{
			if (nums[ind2] > nums[ind1])
				break;
		}
		swap(nums[ind1], nums[ind2]);
		reverse(nums.begin() + ind1 + 1, nums.end());
	}


}


void permute(string s, int l, int r, vector<string>&re)
{
	if (l == r)
	{
		re.push_back(s);
		return;
	}
	for (int j = l; j <= r; j++)
	{
		swap(s[l], s[j]);
		permute(s, l + 1, r, re);
		swap(s[l], s[j]);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		vector<string> res;
		permute(s, 0, s.size() - 1, res);
		sort(res.begin(), res.end());
		for (auto i : res)
			cout << i << " ";
		cout << endl;
		int idx = lower_bound(res.begin(), res.end(), s) - res.begin();
		if (idx + 1 == res.size())
			cout << res[0] << endl;
		else
			cout << res[idx + 1] << endl;
	}


	return 0;
}