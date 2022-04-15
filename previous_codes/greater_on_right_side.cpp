#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
		// code here
		int mx = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			int a = arr[i];
			arr[i] = mx;
			mx = max(mx, a);
		}

	}


};

class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {

		vector<int> r;
		for (int i = 0; i < arr.size(); i++)
		{
			int next = -1;
			for (int j = i + 1; j < arr.size(); j++)
			{
				next = max(arr[j], next);
			}
			r.push_back(next);
		}
		return r;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}
