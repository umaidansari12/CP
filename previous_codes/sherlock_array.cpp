#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string balancedSums(vector<int> arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		int left_sum = 0, right_sum = 0;
		for (int j = 0; j < i; j++)
			left_sum += arr[j];
		for (int j = i + 1; j < n; j++)
			right_sum += arr[j];
		if (left_sum == right_sum)
			return "YES";
	}
	return "NO";

}


string balancedSums(vector<int> arr) {
	int n = arr.size();
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int left_sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum -= arr[i];
		if (left_sum == sum)
			return "YES";
		left_sum += arr[i];

	}
	return "NO";

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}