#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
The stocks of a company are being surveyed to analyze the profit of
the company over a period of several months. For an analysis
parameter k, a group of k consecutive months is said to be highly
profitable if the values of the stock prices are strictly increasing
for those months.Gien the stock prices of the company for n months
and the analysis parameters k , find the number of highly profitale
months

Intuition : Brute force find k size subarrays which are strictly increasing
Time Complexity : O(N^2)
Space Complexity : O(1)

12/15 test cases passed 3 test cases TLE

Input : stockPrices = [5,3,5,7,8]
k = 3

Output : 2
[3,5,7] and [5,7,8] these 2 k size groups are strictly increasing.
*/

int countHighlyProfitableMonthsBrute(vector<int> stockPrices, int k) {
	int n = stockPrices.size(), answer = 0;
	// start from 0 move to k start from 1 move to k+1
	//_k is used to fixed starting point and then from _k to _k+k will be used to traversed the k sized subarray and check if the subarray is strictly increasing or not
	for (int _k = 0; _k < (n - k) + 1; _k++) {
		bool f = true;//initially a flag variable is taken whose value is true so as to mark that the array is strictly increasing and if while traversing the k size subarray if any point of time we found that the element is not strictly greater we make flag varible as false making that the current k sized subarray will not be counted in our answer
		for (int i = _k; i < (_k + k) - 1; i++) {
			if (stockPrices[i] >= stockPrices[i + 1])
			{
				f = false;
				break;
			}
		}
		if (f)
			answer++;
	}
	return answer;
}
int countHighlyProfitableMonths(vector<int> stockPrices, int k) {
	int n = stockPrices.size(), count = 1;
	vector<int> a;
	for (int i = 0; i + 1 < n; i++) {
		if (stockPrices[i + 1] > stockPrices[i])
			count += 1;
		else {
			a.push_back(count);
			count = 1;
		}
	}
	a.push_back(count);
	int ans = 0;
	for (auto x : a) {
		if (x >= k)
			ans += (x - k + 1);
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> stockPrices(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> stockPrices[i];
		}
		cout << countHighlyProfitableMonths(stockPrices, k) << " " << countHighlyProfitableMonthsBrute(stockPrices, k) << endl;
	}

	return 0;
}