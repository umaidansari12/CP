#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Use hash map and calculate number of distinct elements of every window of size k.

An Efficient Solution is to use the count of the previous window while sliding the window.
The idea is to create a hash map that stores elements of the current window. When we slide the window,
we remove an element from the hash and add an element. We also keep track of distinct elements.*/

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, k, i = 0, c = 0, j = 0;
		cin >> n >> k;
		vector<int> a(n), count(10000, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		/*map<int, int> count;
		for (i = 0; i < k; i++)
		{
			if (count[a[i]] == 0)
			{
				c++;
			}
			count[a[i]]++;
		}
		cout << c << " ";
		for (; i < n; i++)
		{
			if (count[a[i - k]] == 1)
			{
				c--;
			}
			count[a[i - k]]--;
			if (count[a[i]] == 0)
			{
				c++;
			}
			count[a[i]]++;
			cout << c << " ";
		}*/

		//int i = 0, j = 0, c = 0;
		while (j < k)
		{
			if (count[a[j]] == 0)
			{
				c++;
			}
			count[a[j]]++;
			j++;
		}
		i++;
		cout << c << " ";
		while (j < n)
		{
			if (count[a[j - k]] == 1)
			{
				count[a[j - k]]--;
				c--;
			}
			if (count[a[j]] == 0)
			{
				c++;
			}
			cout << c << " ";

			j++;

			/*else
			{
				count[a[j]]++;
			}
			cout << c << " ";
			count[a[i++]]--;
			c--;
			j++;*/

		}
		cout << endl;
		//cout << c << endl;

	}


	return 0;
}

vector <int> countDistinct (int A[], int n, int k)
{
	unordered_map<int, int> um;
	vector <int> result;
	// count number of distinct elements for first window of size k
	for (int i = 0; i < k; i++)
		um[A[i]]++;

	result.push_back(um.size());

	// calculate answer for rest of the windows
	for (int i = 1; i < n - k + 1; i++)
	{
		um[A[i - 1]]--;
		if (um[A[i - 1]] <= 0)
			um.erase(A[i - 1]);

		um[A[i + k - 1]]++;

		result.push_back(um.size());
	}
	return result;
}