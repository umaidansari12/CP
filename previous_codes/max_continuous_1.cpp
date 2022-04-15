#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = nums.size();
		int j = 0, i = 0, count = 0;
		while (i < n)
		{
			if (nums[i] == 1)
			{
				j = i + 1;
				while (j < n && nums[j] == 1) j++;
				//count=max(count,j-i);
				if (count < j - i)
					count = j - i;
			}
			i++;
		}
		return count;
	}

};

/*Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.



Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation:
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.


Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1
*/
/*This problem uses two pointer uses sliding window and two pointer approach
in which we increase the size of window keeping start as constant and until we accomodate
maximum of k zeroes so that it can be changed to 1 we keep changing our result to max
*/
class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int n = A.size(), start = 0, end = 0, zeroCount = 0, res = 0;
		for (end = 0; end < n; end++)
		{
			if (A[end] == 0)
				zeroCount++;
			while (zeroCount > K)
			{
				if (A[start] == 0)
					zeroCount--;
				start++;
			}
			res = max(res, end - start + 1);
		}
		return res;
	}

};
/*You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input :
Array = {1 1 0 1 1 0 0 1 1 1 }
M = 1

Output :
[0, 1, 2, 3, 4]

If there are multiple possible solutions, return the sequence which has the minimum start index.

A : [ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0 ]
B : 4
Your function returned the following :
4 5 6 7 8 9 10 11 12 13 14 15 16
The expected returned value :
4 5 6 7 8 9 10 11 12 13 14 15


*/
vector<int> Solution::maxone(vector<int> &A, int B) {
	int n = A.size(), s = 0, e = 0, res = 0, l = 0, r = 0, zc = 0;
	for (e = 0; e < n; e++)
	{
		if (A[e] == 0)
			zc++;
		while (zc > B)
		{
			if (A[s] == 0)
				zc--;
			s++;
		}
		if (res < (e - s + 1) && r < n)
		{
			res = e - s + 1;
			l = s;
			r = e;
		}
	}
	vector<int> re;
	for (int i = l; i <= r; i++)
		re.push_back(i);
	return re;
}

int maxContinuousOnes(vector<int> a, int n)
{
	int count = 0;
	int j = 0, i = 0;
	while (i < n)
	{
		if (a[i] == 1)
		{
			j = i;
			while (j < n && a[j] == 1)
				j++;
			count = max(count, j - i);
		}
		i++;
	}
	return count;
}

int max_ContinuousOnes(vector<int> a, int n)
{
	int count = 0, res = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == 0)
			count = 0;
		else
		{
			count++;
			res = max(res, count);
		}
	}

	return res;
}
/*You need to think about two things as far as any window is concerned. One is the starting point for the window.
How do you detect that a new window of 1s has started? The next part is detecting the ending point for this window.
 How do you detect the ending point for an existing window? If you figure these two things out, you will be able to detect
 the windows of consecutive ones. All that remains afterward is to find the longest such window and return the size.*/
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = nums.size(), cnt = 0, res = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == 1)
			{
				cnt++;
				res = max(res, cnt);
			}
			else
				cnt = 0;
		}
		return res;

	}
};

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = nums.size();
		int count = 0, res = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == 0)
				count = 0;
			else
			{
				count++;
				res = max(res, count);
			}
		}

		return res;
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << maxContinuousOnes(a, n) << endl;


	}


	return 0;
}