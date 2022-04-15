#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void subArraySum(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// Maintains sum of elements so far
	int curr_sum = 0;

	for (int i = 0; i < n; i++)
	{
		// add current element to curr_sum
		curr_sum = curr_sum + arr[i];

		// if curr_sum is equal to target sum
		// we found a subarray starting from index 0
		// and ending at index i
		if (curr_sum == sum)
		{
			cout << "Sum found between indexes "
			     << 0 << " to " << i << endl;
			return;
		}

		// If curr_sum - sum already exists in map
		// we have found a subarray with target sum
		if (map.find(curr_sum - sum) != map.end())
		{
			cout << "Sum found between indexes "
			     << map[curr_sum - sum] + 1
			     << " to " << i << endl;
			return;
		}

		map[curr_sum] = i;
	}

	// If we reach here, then no subarray exists
	cout << "No subarray with given sum exists";
}
//this doesnt handle negative numbers
void subarrayWithGivenSum(vector<int> a, int n, int s)
{
	/*two pointer approach increasing the size of subarray when the current sum
	is less than k but when gretaer then decrease the sum from left pointer and if sum equals k return */
	int i = 0, j = 0, l = 1, r = 1, sum = a[0], flag = 0;
	while (j != n - 1)
	{
		if (sum + a[j + 1] < s)
		{
			j++;
			sum += a[j];
		}
		else if (sum == s)
		{
			flag = 1;
			l = i + 1;
			r = j + 1;
			break;
		}
		else if (sum + a[j + 1] == s)
		{
			j++;
			flag = 1;
			l =  (i + 1);
			r = (j + 1);
			break;
		}
		else
		{
			sum -= a[i++];
		}
	}
	if (flag)
		cout << l << " " << r << endl;
	else
		cout << -1 << endl;
}

//this code will handle negative numbers

void subArraywithGivenSum(vector <int> a, int n, int s)
{
	int i = 0, curr_sum = 0, count = 0;
	unordered_map<int, int> m;
	while (i < n)
	{
		curr_sum += a[i];
		if (curr_sum == s)
		{
			count++;
		}
		if (m.find(curr_sum - s) != m.end())
		{
			count += m[curr_sum - s];
		}
		m[curr_sum]++;
		i++;
	}
	cout << count << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> s;
		subarrayWithGivenSum(a, n, s);
	}


	return 0;
}