#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//think about using binary search which can be further optimized using two pointer approach

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int r, c;
	cin >> r >> c;
	vector<vector<int>> a(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	int ans = -1, prev = 0;
	for (int i = 0; i < r; i++)
	{
		int n = 0;
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 1)
			{
				n = c - j;
				break;
			}
		}
		if (prev < n)
		{
			prev = n;
			ans = i;
		}
	}
	cout << ans << endl;


	return 0;
}
class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
		// code here
		int ans = -1, prev = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			int c = count(arr[i].begin(), arr[i].end(), 1);
			if (c > prev)
			{
				prev = c;
				ans = i;
			}
		}
		return ans;
	}

};

class Solution {

private:
	int get(int i, int j)
	{
		return a.get(i, j); //return A[i][j]
	}
public:

	int solve(int R, int C) {
		int answer = 0, last = C;
		for (int i = 0; i < R; i++)
		{
			while (last > 0 && get(i, last - 1) == 1)
			{
				answer = i;
				last--;
			}
		}
		return answer;
	}
};
class Solution {
private:
	// do not edit this function
	// use it to get the value of A[i][j]
	int get(int i, int j) {
		return a.get(i, j);
	}
public:
	int solve(int R, int C) {
		//code here
		int ans = -1, prev = 0;
		for (int i = 0; i < R; i++)
		{
			int n = 0;
			for (int j = 0; j < C; j++)
			{
				if (get(i, j) == 1)
				{
					n = C - j;
					break;
				}
			}
			if (prev < n)
			{
				prev = n;
				ans = i;
			}
		}
		return ans;
	}
};